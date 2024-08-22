#include <api.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <password.h>
#include <ArduinoJson.h>
#include <neopixel.h>
#include <main.h>

const char* ssid = "hpi_event";

AsyncWebServer server(80);

void setup_api() {
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

  // Define a route to serve the HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");        // for debugging
    request->send(200, "text/html", "<html><body><h1>Hello, ESP32! Plea</h1></body></html>");
  });

  server.on("/getSettings", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("getSettings called");

    JsonDocument doc;

    doc["brightness"] = settings::brightness;
    doc["red"] = settings::red;
    doc["green"] = settings::green;
    doc["blue"] = settings::blue;

    char output[512];
    serializeJson(doc, output);

    request->send(200, "application/json", output);
  });

  server.on("/setSettings", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("setSettings called");

    int params = request->params();


    for(int i=0;i<params;i++){
      AsyncWebParameter* p = request->getParam(i);
      Serial.printf("GET[%s]: %s\n", p->name().c_str(), p->value().c_str());

      if (!strcmp(p->name().c_str(), "brightness")) {
        settings::brightness = std::stoi(p->value().c_str());
        Serial.println("brightness changed:" + String(settings::brightness));
      }
      if (!strcmp(p->name().c_str(), "red")) {
        settings::red = std::stoi(p->value().c_str());
      } 
      if (!strcmp(p->name().c_str(), "green")) {
        settings::green = std::stoi(p->value().c_str());
      } 
      if (!strcmp(p->name().c_str(), "blue")) {
        settings::blue = std::stoi(p->value().c_str());
      }
    }

    request->send(200, "text/html", "ok.");
  });

  server.on("/changeMode", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("changeMode called");

    switch_state++;
    switch_state = switch_state % 3;

    request->send(200, "text/html", "ok. new mode: " + String(switch_state));
  });

  // Start the server
  server.begin();
}


void handleBody(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total){
  if(!index){
    Serial.printf("BodyStart: %u B\n", total);
  }
  for(size_t i=0; i<len; i++){
    Serial.write(data[i]);
  }
  if(index + len == total){
    Serial.printf("BodyEnd: %u B\n", total);
  }
}
