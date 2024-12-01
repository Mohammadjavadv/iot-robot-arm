#include <WiFi.h>
#include <ArduinoWebsockets.h>

const char *ssid = "AndroidAP";
const char *password = "mjv05086";
const char *serverAddres = "ws://192.168.43.171:5500/web/Frontend/index.html";

using namespace websockets;

void messageCallBack(WebsocketsMessage message)
{
    if (message.data() == "forward")
    {
        Serial.println("forward");
    }
    if (message.data() == "backward")
    {
        Serial.println("backward");
    }
    if (message.data() == "right")
    {
        Serial.println("right");
    }
    if (message.data() == "left")
    {
        Serial.println("left");
    }
    if (message.data() == "topRight")
    {
        Serial.println("topRight");
    }
    if (message.data() == "topLeft")
    {
        Serial.println("topLeft");
    }
    if (message.data() == "bottomRight")
    {
        Serial.println("bottomRight");
    }
    if (message.data() == "bottomLeft")
    {
        Serial.println("bottomLeft");
    }
}

void onEventsCallback(WebsocketsEvent event, String data)
{
    if (event == WebsocketsEvent::ConnectionOpened)
    {
        Serial.println("Connnection Opened");
    }
    else if (event == WebsocketsEvent::ConnectionClosed)
    {
        Serial.println("Connnection Closed");
    }
    else if (event == WebsocketsEvent::GotPing)
    {
        Serial.println("Got a Ping!");
    }
    else if (event == WebsocketsEvent::GotPong)
    {
        Serial.println("Got a Pong!");
    }
}

WebsocketsClient client;

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    Serial.println("Try connecting To " + String(ssid));

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }

    Serial.println("Connected To " + String(ssid) + "successfully :)");

    client.onMessage(messageCallBack);
    client.onEvent(onEventsCallback);

    client.connect(serverAddres);
    client.send("Hello Server :)");
    client.ping();
}

void loop()
{
    client.poll();
}
