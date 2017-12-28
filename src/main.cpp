#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/Relays.h"
#include "../interfaces/mcp3204.h"
#include "../interfaces/digital_input.h"


//**************  testing web  **********
#include <unistd.h> /* read, write, close */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <cstdlib>
#include <string.h>
void error(const char *msg) { perror(msg); exit(0); }



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

int ADC_Read(int ch)
    {
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
    
    




    int portno =        80;
    char *host =        "10.116.1.77";
    char *message_fmt = "POST /status/post.json?json={\"btn1\": false,\"btn2\": false,\"btn3\": false,\"btn4\": false} HTTP/1.1\r\nHost: 10.116.1.77/status\r\nConnection: close\r\n\r\n";
    
    
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char request[1024],response[4096];

    //if (argc < 3) { puts("Parameters: <apikey> <command>"); exit(0); }

    // fill in the parameters
    sprintf(request,message_fmt);
    printf("Request:\n%s\n",request);

    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // lookup the ip address
    server = gethostbyname(host);
    cout << server << endl;
    if (server == NULL) error("ERROR, no such host");

    // fill in the structure
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    // connect the socket
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // send the request
    total = strlen(request);
    sent = 0;
    do {
        bytes = write(sockfd,request+sent,total-sent);
        if (bytes < 0)
            error("ERROR writing message to socket");
        if (bytes == 0)
            break;
        sent+=bytes;
    } while (sent < total);

    // receive the response
    memset(response,0,sizeof(response));
    total = sizeof(response)-1;
    received = 0;
    do {
        bytes = read(sockfd,response+received,total-received);
        if (bytes < 0)
            error("ERROR reading response from socket");
        if (bytes == 0)
            break;
        received+=bytes;
    } while (received < total);

    if (received == total)
        error("ERROR storing complete response from socket");

    // close the socket
    close(sockfd);

    // process response
    printf("Response:\n%s\n",response);
    
    
    
    return 1;

    
    
    
    
    
    
    
    
    
    
    
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