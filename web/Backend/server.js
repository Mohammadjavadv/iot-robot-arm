const http = require("http");
const webSocket = require("ws");

const server = http.createServer();

const ws = new webSocket.Server({ server })

ws.on("headers", (headers) => {
    console.log("Headers =>", headers);
})

ws.on("connection", (socket) => {
    console.log("New user Connected");
    socket.on("message", (data) => {
        console.log(`Client Message => ${data.toString('utf-8') }`);
        ws.clients.forEach(client => {
            client.send(data.toString('utf-8'))
        })
    })
})



server.listen(5500, () => {
    console.log("Server Running In Port 5500 :)");
});