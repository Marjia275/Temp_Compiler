const path = require('path');
const runCompiler = require('./runCompiler');

function runCpp(ws, sourceCode) {
  const binaryPath = path.join(__dirname, '..', '..', 'CPP_Compiler', 'compiler.exe');
  return runCompiler(ws, { binaryPath, sourceCode, fileExtension: '.cpp' });
}

module.exports = runCpp;