#include <sys/socket.h>

#include "web_server.h"



 struct addrinfo hints, *server;
 memset(&hints, 0, sizeof hints);
 hints.ai_family =  AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 hints.ai_flags = AI_PASSIVE || SOCK_NONBLOCK;
 getaddrinfo(NULL, "80", &hints, &server);

 int sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
 bind(sockfd, server->ai_addr, server->ai_addrlen);
 listen(sockfd, 10);
 
 struct sockaddr_storage client_addr;
 socklen_t addr_size = sizeof client_addr;
 char headers[] = "HTTP/1.0 200 OK\r\nServer: CPi\r\nContent-type: text/html\r\n\r\n";
 char buffer[2048];
 
 char data[2048] = {0};
 snprintf(data, sizeof data, "%s %s", headers, html);





AsyncWebServer server(80);          //Create class for Web server




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

  DynamicJsonBuffer jsonBuffer;
String s = "{";
s += "\"btn1\":\""+"true"+"\",";
s += "\"btn2\":\""+"true"+"\",";
s += "\"btn3\":\""+"false"+"\",";
s += "\"btn4\":\""+"true"+"\"";
s += "}";
  
  response->setCode(200);
  response->print(s);
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
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

  // Start server & server root html /
  server.on("/", handleHome);

  server.on("/status", handleStatus);

  server.on("/btn1", handletBTN1);
  server.onNotFound(handleNotFound);
  server.begin();
}

void web_server_loop(void) {
}
