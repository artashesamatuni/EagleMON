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

using namespace std;

//#include "lasote/httpserver/http_server.h"
//#include "server.h"

//using namespace httpserver;
//using namespace gip;


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


int main(void) {

    int portno =        80;
    char *host =        "localhost";
    char *message_fmt = "POST /status/{Tempr:25}";

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char message[1024],response[4096];

    //if (argc < 3) { puts("Parameters: <apikey> <command>"); exit(0); }

    /* fill in the parameters */
    sprintf(message,message_fmt);
    printf("Request:\n%s\n",message);

    /* create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    /* lookup the ip address */
    server = gethostbyname(host);
    if (server == NULL) error("ERROR, no such host");

    /* fill in the structure */
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    /* connect the socket */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    /* send the request */
    total = strlen(message);
    sent = 0;
    do {
        bytes = write(sockfd,message+sent,total-sent);
        if (bytes < 0)
            error("ERROR writing message to socket");
        if (bytes == 0)
            break;
        sent+=bytes;
    } while (sent < total);

    /* receive the response */
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

    /* close the socket */
    close(sockfd);

    /* process response */
    printf("Response:\n%s\n",response);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // ADC testing
    int ch1_data = ADC_Read(0);
    cout << ch1_data << "\r" << endl;
    
    digital_input Input_1(2, 1);

    
    /*--------------------------File Read/Write Part--------------------------------*/

    FILE * pFile;
   
    cout << "simple print\r" <<endl;

    pFile = fopen ("/root/myconfig.json","w");
    fprintf (pFile, "test");
    fclose (pFile);
    
    //fflush(stdout);

    
    
    /*----------------------Relay Control Part--------------------------------*/
    
    Relay Relay_1(0);
    
    for(;;)
        {
            if (Input_1.read())
            {
                cout << "Input True\r" <<endl;
            }
            else
            {
                cout << "Input False\r" <<endl;
            }
        
        
            if(Relay_1.state())
            {
            Relay_1.off();
            delay(500);
            }
            else
            {
            Relay_1.on();
            delay(500);
            }
        }
    
        
 	/*MyHttpMiddleware my_mmiddleware;
	HttpServerConf conf(80, 300, 60, 5);

	HttpServer http_server;

	http_server.run(&my_mmiddleware, &conf);
        */
 return 0;
}