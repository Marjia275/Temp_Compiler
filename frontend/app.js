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

// xterm defaults to a fixed 80x24 grid and has no idea how tall its
// container actually is. Without resizing it manually, it only fills the
// top ~24 rows, leaving the rest of the panel blank. This measures the
// real cell size xterm rendered with and resizes the grid to match the
// container, so it fills the available space edge to edge.
function fitTerminal() {
  const container = document.getElementById('terminal');
  const core = term._core;
  if (!container || !core || !core._renderService) return;

  const dims = core._renderService.dimensions;
  const cellWidth = dims && dims.css && dims.css.cell && dims.css.cell.width;
  const cellHeight = dims && dims.css && dims.css.cell && dims.css.cell.height;
  if (!cellWidth || !cellHeight) return;

  const cols = Math.max(2, Math.floor(container.clientWidth / cellWidth));
  const rows = Math.max(1, Math.floor(container.clientHeight / cellHeight));

  if (cols !== term.cols || rows !== term.rows) {
    term.resize(cols, rows);
  }
}

// Fit once after the terminal has finished its initial render, then keep
// it in sync whenever the window (or panel) is resized.
requestAnimationFrame(fitTerminal);
window.addEventListener('resize', fitTerminal);


const runBtn = document.getElementById('runBtn');
const stopBtn = document.getElementById('stopBtn');
const clearBtn = document.getElementById('clearBtn');
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
  fitTerminal();
  term.clear();
  inputBuffer = '';

  // Always talk to the backend on its fixed port (3000), regardless of
  // what port/tool actually served this HTML page. This makes Run work
  // whether the page was opened via node's own server (localhost:3000)
  // or via a separate static server like VS Code's Live Server (5500) —
  // as long as `node server.js` is running in the background.
  const BACKEND_PORT = 3000;
  ws = new WebSocket(`ws://${location.hostname}:${BACKEND_PORT}`);

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

clearBtn.addEventListener('click', () => {
  term.clear();
});

stopBtn.addEventListener('click', () => {
  if (ws) {
    ws.send(JSON.stringify({ type: 'stop' }));
    ws.close();
  }
  setRunning(false);
});