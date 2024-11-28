const $ = document;
const robotBtns = $.querySelectorAll(".button-img")
let host = location.origin.replace(/^http/, 'ws');
console.log(host);
const socket = new WebSocket("ws://localhost:5500")

// const socket = new WebSocket(host);

console.log(socket);



socket.addEventListener("open", () => {
    console.log("Connected to server");
    robotBtns.forEach((robotBtn) => {
        robotBtn.addEventListener("mousedown", (ev) => {
            console.log(ev.target.id);
            socket.send(ev.target.id)
        })
        robotBtn.addEventListener("mouseup", (ev) => {
            socket.send("stop");
        })
        robotBtn.addEventListener("touchstart", (ev) => {
            socket.send(ev.target.id)
            console.log(ev.target.id);
        })
        robotBtn.addEventListener("touchend", (ev) => {
            socket.send("stop");
        })
    })
    socket.addEventListener("message", (ev) => {
        // console.log(ev.data);
    })
})