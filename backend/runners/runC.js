const path = require('path');
const runCompiler = require('./runCompiler');

function runC(ws, sourceCode) {
  const binaryPath = path.join(__dirname, '..', '..', 'C_Compiler', 'compiler.exe');
  return runCompiler(ws, { binaryPath, sourceCode, fileExtension: '.c' });
}

module.exports = runC;