const path = require('path');
const runCompiler = require('./runCompiler');

function runJava(ws, sourceCode) {
  const binaryPath = path.join(__dirname, '..', '..', 'Java_Compiler', 'compiler.exe');
  return runCompiler(ws, { binaryPath, sourceCode, fileExtension: '.java' });
}

module.exports = runJava;