#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/Relays.h"
#include "../interfaces/mcp3204.h"
#include "../interfaces/digital_input.h"

#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include <cstdio>

using namespace std;
using namespace rapidjson;

//#include "lasote/httpserver/http_server.h"
//#include "server.h"

//using namespace httpserver;
//using namespace gip;

bool init = false;

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
    
        /*--------------------------File Read/Write Part--------------------------------*/
/*
    FILE * pFile;
   
    cout << "simple print\r" <<endl;

    pFile = fopen ("/root/config.json","r");
    printf (pFile, "test");
    fclose (pFile);
*/
    
    const char json[] = "{\"Polarity\":[true,true,true,false],\"Status\":[false,true,false,false],\"Note\":[\"Relay 1\", \"Pump\", \"ALARM\", \"Empty\"] }";
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
        {
            // Write settings to ...
            printf("Relay[%d]: Status - %s \t Polarity - %s \t Note - %s \r\n", i, stat[i].GetBool() ? "true" : "false", pol[i].GetBool() ? "true" : "false", note[i].GetString());
        }
        init = true;
    } 
    return true;
}



int main(void) {
    if(!init)
        setup();
    // ADC testing
    int ch1_data = ADC_Read(0);
    cout << ch1_data << "\r" << endl;
    
    digital_input Input_1(2, 1);

    

    
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
            delay(100);
            }
            else
            {
            Relay_1.on();
            delay(100);
            }
        }
    
 return 0;
}