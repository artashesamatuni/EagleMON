#include <stdio.h>
#include <stdlib.h>
#include "Relays.h"
#include "interfaces/mcp3204.h"

using namespace std;

//#include "lasote/httpserver/http_server.h"
//#include "server.h"

//using namespace httpserver;
//using namespace gip;


int main(void) {
    
    /*--------------------------SPI ADC Part--------------------------------*/
    
    mcp3204 ADC("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);     // Init ADC
    
    int i = 5;
    int ADCVal = 0;
    int ADCChannel = 0;
    unsigned char data[3];
 
    while(i > 0)
    {
        data[0] = 1;  //  first byte transmitted -> start bit
        data[1] = 0b10000000 |( ((ADCChannel & 7) << 4)); // second byte transmitted -> (SGL/DIF = 1, D2=D1=D0=0)
        data[2] = 0; // third byte transmitted....don't care
 
        ADC.spiWriteRead(data, sizeof(data) );
 
        ADCVal = 0;
                ADCVal = (data[1]<< 8) & 0b1100000000; //merge data[1] & data[2] to get result
                ADCVal |=  (data[2] & 0xff);
        sleep(1);
        cout << "The Result is: " << ADCVal << "\r" <<endl;
        i--;
    }
    
    
    
    /*--------------------------File Read/Write Part--------------------------------*/

    FILE * pFile;
    int n;
    char name [100];
   
    char *message[3] = {"msss1", "mass2", "mss3"};
    char array[20] = "Hello World";
    printf("%s\n\r",message[2]);
    printf("text");

    pFile = fopen ("myconfig.json","w");
    fprintf (pFile, "test");
    fclose (pFile);
    
    fflush(stdout);

    
    
    /*----------------------Relay Control Part--------------------------------*/
    
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