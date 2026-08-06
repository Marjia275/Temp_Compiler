const term = new Terminal({
  theme: {
    background: '#ecf1f4',
    foreground: '#000000',
    cursor: '#CFAB8D',
    cursorAccent: '#2E2418',
    selectionBackground: '#8A6A4C'
  },
  fontFamily: '"Consolas", "Courier New", monospace',
  fontSize: 15,
  lineHeight: 1.3,
  cursorBlink: true
});


term.open(document.getElementById('terminal'));
term.writeln('Waiting to run your code...');


const runBtn = document.getElementById('runBtn');
const stopBtn = document.getElementById('stopBtn');
const languageSelect = document.getElementById('language');

// Map our language <select> values to CodeMirror's clike MIME modes.
const LANGUAGE_MODES = {
  c: 'text/x-csrc',
  cpp: 'text/x-c++src',
  java: 'text/x-java'
};

const editor = CodeMirror(document.getElementById('editor'), {
  value: '',
  mode: LANGUAGE_MODES[languageSelect.value],
  theme: 'vscode-dark',
  lineNumbers: true,
  matchBrackets: true,
  styleActiveLine: true,
  indentUnit: 4,
  tabSize: 4,
  indentWithTabs: false,
  autofocus: true,
  placeholder: 'Write your code here...'
});
editor.setSize('100%', '100%');

languageSelect.addEventListener('change', () => {
  editor.setOption('mode', LANGUAGE_MODES[languageSelect.value]);
});

let ws = null;
let inputBuffer = '';
let isRunning = false;

function setRunning(running) {
  isRunning = running;
  runBtn.disabled = running;
  stopBtn.disabled = !running;
}

function connectAndRun() {
  term.clear();
  inputBuffer = '';

  ws = new WebSocket(`ws://${location.host}`);

  ws.onopen = () => {
    setRunning(true);
    ws.send(JSON.stringify({
      type: 'run',
      language: languageSelect.value,
      code: editor.getValue()
    }));
  };

  ws.onmessage = (event) => {
    const data = JSON.parse(event.data);
    if (data.type === 'output') {
      term.write(data.text.replace(/\n/g, '\r\n'));
    } else if (data.type === 'system') {
      term.write(`\r\n\x1b[33m${data.text.replace(/\n/g, '\r\n')}\x1b[0m`);
    } else if (data.type === 'exit') {
      term.write(`\r\n\x1b[36m[Program exited with code ${data.code}]\x1b[0m\r\n`);
      setRunning(false);
    }
  };

  ws.onclose = () => {
    setRunning(false);
  };

  ws.onerror = () => {
    term.write('\r\n\x1b[31m[Connection error]\x1b[0m\r\n');
    setRunning(false);
  };
}

// Forward typed characters into the running program's stdin.
// Echo locally so the user sees what they type, and send the whole
// line (with newline) once Enter is pressed — matching cin/scanf/Scanner behavior.
term.onData((char) => {
  if (!isRunning || !ws || ws.readyState !== WebSocket.OPEN) return;

  if (char === '\r') {
    term.write('\r\n');
    ws.send(JSON.stringify({ type: 'input', text: inputBuffer + '\n' }));
    inputBuffer = '';
  } else if (char === '\u007F') { // Backspace
    if (inputBuffer.length > 0) {
      inputBuffer = inputBuffer.slice(0, -1);
      term.write('\b \b');
    }
  } else {
    inputBuffer += char;
    term.write(char);
  }
});

runBtn.addEventListener('click', connectAndRun);

stopBtn.addEventListener('click', () => {
  if (ws) {
    ws.send(JSON.stringify({ type: 'stop' }));
    ws.close();
  }
  setRunning(false);
});