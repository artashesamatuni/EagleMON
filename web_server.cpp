#include <Arduino.h>
#include <ESP8266WiFi.h>
                     // SPIFFS file-system: store web server html, CSS etc.
#include <ArduinoJson.h>

#include "esp.h"
#include "web_server.h"



AsyncWebServer server(80);          //Create class for Web server

bool enableCors = true;

// Event timeouts
unsigned long wifiRestartTime = 0;
unsigned long mqttRestartTime = 0;
unsigned long ntpRestartTime = 0;
unsigned long systemRestartTime = 0;
unsigned long systemRebootTime = 0;

// Get running firmware version from build tag environment variable
#define TEXTIFY(A) #A
#define ESCAPEQUOTE(A) TEXTIFY(A)
String currentfirmware = ESCAPEQUOTE(3.0);

FSInfo fs_info;
// -------------------------------------------------------------------
// Helper function to perform the standard operations on a request
// -------------------------------------------------------------------
bool requestPreProcess(AsyncWebServerRequest *request, AsyncResponseStream *&response, const char *contentType = "application/json")
{
  if (www_username != "" && !request->authenticate(www_username.c_str(), www_password.c_str())) {
    request->requestAuthentication();
    return false;
  }

  response = request->beginResponseStream(contentType);
  if (enableCors) {
    response->addHeader("Access-Control-Allow-Origin", "*");
  }

  return true;
}

// -------------------------------------------------------------------
// Load Home page
// url: /
// -------------------------------------------------------------------
void handleHome(AsyncWebServerRequest *request) {


}

// -------------------------------------------------------------------
// Returns status json
// url: /status
// -------------------------------------------------------------------
void handleStatus(AsyncWebServerRequest *request) {
  AsyncResponseStream *response;
  if (false == requestPreProcess(request, response)) {
    return;
  }
  DynamicJsonBuffer jsonBuffer;
  String frame = "";
  JsonObject& root = jsonBuffer.createObject();
  JsonArray& networks = root.createNestedArray("networks");
  JsonArray& rssi = root.createNestedArray("rssi");


  root["btn1"] = true;
  root["btn2"] = true;
  root["btn3"] = false;
  root["btn4"] = false;
  
  root.printTo(frame);
  response->setCode(200);
  response->print(frame);
  request->send(response);
}


// -------------------------------------------------------------------
// url: /btn1
// -------------------------------------------------------------------
void handletBTN1(AsyncWebServerRequest * request) {
  AsyncResponseStream *response;
  if (false == requestPreProcess(request, response, "text/plain")) {
    return;
  }
  //CHANGE btn1 status
  request->send(response);
}


void handleNotFound(AsyncWebServerRequest * request)
{
  DBUG("NOT_FOUND: ");
  if (request->method() == HTTP_GET) {
    DBUGF("GET");
  } else if (request->method() == HTTP_POST) {
    DBUGF("POST");
  } else if (request->method() == HTTP_DELETE) {
    DBUGF("DELETE");
  } else if (request->method() == HTTP_PUT) {
    DBUGF("PUT");
  } else if (request->method() == HTTP_PATCH) {
    DBUGF("PATCH");
  } else if (request->method() == HTTP_HEAD) {
    DBUGF("HEAD");
  } else if (request->method() == HTTP_OPTIONS) {
    DBUGF("OPTIONS");
  } else {
    DBUGF("UNKNOWN");
  }
  DBUGF(" http://%s%s", request->host().c_str(), request->url().c_str());

  if (request->contentLength()) {
    DBUGF("_CONTENT_TYPE: %s", request->contentType().c_str());
    DBUGF("_CONTENT_LENGTH: %u", request->contentLength());
  }

  int headers = request->headers();
  int i;
  for (i = 0; i < headers; i++) {
    AsyncWebHeader* h = request->getHeader(i);
    DBUGF("_HEADER[%s]: %s", h->name().c_str(), h->value().c_str());
  }

  int params = request->params();
  for (i = 0; i < params; i++) {
    AsyncWebParameter* p = request->getParam(i);
    if (p->isFile()) {
      DBUGF("_FILE[%s]: %s, size: %u", p->name().c_str(), p->value().c_str(), p->size());
    } else if (p->isPost()) {
      DBUGF("_POST[%s]: %s", p->name().c_str(), p->value().c_str());
    } else {
      DBUGF("_GET[%s]: %s", p->name().c_str(), p->value().c_str());
    }
  }

  request->send(404);
}

void web_server_setup(void)
{

  // Setup the static files
  server.serveStatic("/", SPIFFS, "/")
  .setDefaultFile("index.html")

  // Start server & server root html /
  server.on("/", handleHome);

  // Handle HTTP web interface button presses
  server.on("/generate_204", handleHome);  //Android captive portal. Maybe not needed. Might be handled by notFound
  server.on("/fwlink", handleHome);  //Microsoft captive portal. Maybe not needed. Might be handled by notFound

  server.on("/status", handleStatus);

  server.on("/btn1", handletBTN1);
  server.onNotFound(handleNotFound);
  server.begin();
}

void web_server_loop(void) {
}
