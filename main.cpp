#include <stdio.h>
#include <stdlib.h>
#include "Relays.h"
#include "interfaces/mcp3204.h"

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
    
    int ch1_data = ADC_Read(0);
    cout << ch1_data << "\r" << endl;

    
    /*--------------------------File Read/Write Part--------------------------------*/

    FILE * pFile;
    int n;
    char name [100];
   
    cout << "simple print\r" <<endl;

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