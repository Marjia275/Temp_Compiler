const express = require('express');
const http = require('http');
const { WebSocketServer } = require('ws');
const path = require('path');
const handleConnection = require('./socketHandler');

const app = express();

app.use((req, res, next) => {
  res.setHeader(
    'Content-Security-Policy',
    "default-src 'self'; style-src 'self' 'unsafe-inline'; connect-src 'self' ws://localhost:3000"
  );
  next();
});

const server = http.createServer(app);
const wss = new WebSocketServer({ server });

app.use(express.static(path.join(__dirname, '..', 'frontend')));

wss.on('connection', handleConnection);

const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});