#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/Relays.h"
#include "../interfaces/mcp3204.h"
#include "../interfaces/digital_input.h"

////////////////////////////////////web
 
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
 
 
 
/////////////////////////////////////////




//*************  JSON part  **************
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include <cstdio>


using namespace std;
using namespace rapidjson;

bool init = false;
Relay   Relay_1(0),
        Relay_2(1),
        Relay_3(2),
        Relay_4(3);



int statusREQ()
{
  struct addrinfo hints, *server;
 memset(&hints, 0, sizeof hints);
 hints.ai_family =  AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 hints.ai_flags = AI_PASSIVE || SOCK_NONBLOCK;
 getaddrinfo(NULL, "85", &hints, &server);
 
 int sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
 bind(sockfd, server->ai_addr, server->ai_addrlen);

 listen(sockfd, 10);
 
 struct sockaddr_storage client_addr;
 socklen_t addr_size = sizeof client_addr;
 char headers[] = "HTTP/1.1 200 OK\r\nServer: CPi\r\nContent-type: text/html\r\n\r\n";
 char buffer[2048];
 char html[] = "{\"btn1\":\"Relay 1\",\"btn2\":\"Pump\",\"btn2\":\"abc\",\"btn4\":\"test\"}";
 char data[2048] = {0};
 snprintf(data, sizeof data, "%s %s", headers, html);
 for (;;) {
  int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &addr_size);
  if (client_fd > 0)
  {
   int n = read(client_fd, buffer, 2048);
   //printf("%s", buffer);
   fflush(stdout);
   n = write(client_fd, data, strlen(data));
   printf("%s",data);
   close(client_fd); 
  }
 }
 return 0;   
}



int ADC_Read(int ch) {
        mcp3204 ADC("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);     // Init ADC
        
        unsigned char data[3];      // data to be sent then received
        int ADC_val = 0;
        
        data[0] = 0b00000110 | ((ch & 0b00000100)>>2);
        data[1] = ((ch & 0b00000011) << 6) ;
        data[2] = 0;
        
        ADC.spiWriteRead(data, sizeof(data));       // the same buffer is used
        
        ADC_val = 0;
        ADC_val = (data[1]<< 8) & 0b111100000000; //merge data[1] & data[2] to get result
        ADC_val |=  (data[2] & 0xff);
        
        return ADC_val;
    }

bool setup() {
    

    
    const char json[] = "{\"Polarity\":[false,true,true,false],\"Status\":[false,true,false,false],\"Note\":[\"Relay 1\", \"Pump\", \"ALARM\", \"Empty\"] }";
    Document document;
    
#if 0
    // "normal" parsing, decode strings to new buffers. Can use other input stream via ParseStream().
    if (document.Parse(json).HasParseError())
        return 1;
#else
    // In-situ parsing, decode strings directly in the source string. Source must be string.
    char buffer[sizeof(json)];
    memcpy(buffer, json, sizeof(json));
    if (document.ParseInsitu(buffer).HasParseError())
    {
        init = false;
        return false;
    }
#endif

    {
        const Value& stat = document["Status"];
        assert(stat.IsArray());
        const Value& pol = document["Polarity"];
        assert(pol.IsArray());
        const Value& note = document["Note"];
        assert(note.IsArray());
        for (SizeType i = 0; i < stat.Size(); i++)
            printf("Relay[%d]: Status - %s \t Polarity - %s \t Note - %s \r\n", i, stat[i].GetBool() ? "true" : "false", pol[i].GetBool() ? "true" : "false", note[i].GetString());
        Relay_1.polarity(pol[0].GetBool());
        Relay_2.polarity(pol[1].GetBool());
        Relay_3.polarity(pol[2].GetBool());
        Relay_4.polarity(pol[3].GetBool());

        init = true;
    } 
    return true;
}



int main(void)
{
    cout << "Starting Main\r" << endl;
    
    if(!init)
        printf(setup()? "Configured" : "Config err");
    
    
statusREQ();



    
    
    
    
    
    
    
    
    
    
    
    // ADC testing
    int ch1_data = ADC_Read(0);
    cout << ch1_data << "\r" << endl;

    

    

    
    //fflush(stdout);

    /*------------- Relay & Inout Part -------------------*/
    //Relay Relay_1(0, false);
    digital_input Input_1(2, -1);
    for(;;)
        {
            if (Input_1.read())
            {cout << "Input True\r" <<endl;}
            else
            {cout << "Input False\r" <<endl;}
            


            if(Relay_1.SWstate())
            {
            Relay_1.off();
            delay(1980);
            }
            else
            {
            Relay_1.on();
            delay(20);
            }
        }
    
 return 0;
}