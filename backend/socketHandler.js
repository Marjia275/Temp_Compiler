const runC = require('./runners/runC');
const runCpp = require('./runners/runCpp');
const runJava = require('./runners/runJava');

function handleConnection(ws) {
  console.log('A user connected.');

  let session = null;

  ws.on('message', (raw) => {
    let msg;
    try {
      msg = JSON.parse(raw.toString());
    } catch (e) {
      ws.send(JSON.stringify({ type: 'system', text: '\n[Invalid message received]\n' }));
      return;
    }

    if (msg.type === 'run') {
      if (session) session.stop(); // stop any previous run first

      const { language, code } = msg;
      if (language === 'c') session = runC(ws, code);
      else if (language === 'cpp') session = runCpp(ws, code);
      else if (language === 'java') session = runJava(ws, code);
      else ws.send(JSON.stringify({ type: 'system', text: '\n[Unknown language]\n' }));

    } else if (msg.type === 'input') {
      if (session) session.sendInput(msg.text);

    } else if (msg.type === 'stop') {
      if (session) { session.stop(); session = null; }
    }
  });

  ws.on('close', () => {
    console.log('User disconnected.');
    if (session) session.stop();
  });
}

module.exports = handleConnection;