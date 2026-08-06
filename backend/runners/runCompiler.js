const { spawn } = require('child_process');
const fs = require('fs');
const path = require('path');

const IDLE_TIMEOUT_MS = 60 * 1000;      // kill if no activity for 60s
const HARD_TIMEOUT_MS = 5 * 60 * 1000;  // kill after 5 minutes no matter what

function runCompiler(ws, { binaryPath, sourceCode, fileExtension }) {
  const tempDir = path.join(__dirname, '..', 'temp');
  if (!fs.existsSync(tempDir)) {
    fs.mkdirSync(tempDir, { recursive: true });
  }

  const tempFileName = `program_${Date.now()}${fileExtension}`;
  const tempFilePath = path.join(tempDir, tempFileName);
  fs.writeFileSync(tempFilePath, sourceCode);

  const child = spawn(binaryPath, [tempFilePath]);

  let idleTimer = null;
  let hardTimer = null;

  function resetIdleTimer() {
    if (idleTimer) clearTimeout(idleTimer);
    idleTimer = setTimeout(() => {
      ws.send(JSON.stringify({ type: 'system', text: '\n[Session timed out due to inactivity]\n' }));
      child.kill();
    }, IDLE_TIMEOUT_MS);
  }

  function cleanup() {
    if (idleTimer) clearTimeout(idleTimer);
    if (hardTimer) clearTimeout(hardTimer);
    fs.unlink(tempFilePath, () => {}); // best-effort delete
  }

  hardTimer = setTimeout(() => {
    ws.send(JSON.stringify({ type: 'system', text: '\n[Maximum runtime exceeded — process stopped]\n' }));
    child.kill();
  }, HARD_TIMEOUT_MS);

  resetIdleTimer();

  child.stdout.on('data', (data) => {
    resetIdleTimer();
    ws.send(JSON.stringify({ type: 'output', text: data.toString() }));
  });

  child.stderr.on('data', (data) => {
    resetIdleTimer();
    ws.send(JSON.stringify({ type: 'output', text: data.toString() }));
  });

  child.on('error', (err) => {
    ws.send(JSON.stringify({ type: 'system', text: `\n[Failed to start compiler: ${err.message}]\n` }));
    cleanup();
  });

  child.on('exit', (code) => {
    ws.send(JSON.stringify({ type: 'exit', code }));
    cleanup();
  });

  return {
    sendInput: (text) => {
      resetIdleTimer();
      if (!child.killed) child.stdin.write(text);
    },
    stop: () => {
      child.kill();
      cleanup();
    }
  };
}

module.exports = runCompiler;