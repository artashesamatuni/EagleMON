#include <stdio.h>
#include <stdlib.h>
#include <json/value.h>
#include <fstream>
#include "Relays.h"


//#include "lasote/httpserver/http_server.h"
//#include "server.h"

//using namespace httpserver;
//using namespace gip;


int main(void) {
    char *message[3] = {"msss1", "mass2", "mss3"};
    char array[20] = "Hello World";
    //printf("%s\n\r",message[2]);
    printf("text");
    fflush(stdout);
    
    std::ifstream conf_file("config.json", std::ifstream::binary);
    conf_file >> conf;
    cout<<conf;
    
    Relay Relay_1(0);

    
    for(;;)
        {
            if(Relay_1.state())
            {
            Relay_1.off();
            delay(100);
            }
            else
            {
            Relay_1.on();
            delay(100);
            }
        }
    
        
 	/*MyHttpMiddleware my_mmiddleware;
	HttpServerConf conf(80, 300, 60, 5);

	HttpServer http_server;

	http_server.run(&my_mmiddleware, &conf);
        */
 return 0;
}