#include <stdio.h>
#include <stdlib.h>
#include "lasote/httpserver/http_server.h"
#include "web_server.h"

using namespace httpserver;
using namespace gip;



int main(void) {
    
 	MyHttpMiddleware my_mmiddleware;
	HttpServerConf conf(80, 300, 60, 5);

	HttpServer http_server;

	http_server.run(&my_mmiddleware, &conf);

	return 0;
 return 0;
}