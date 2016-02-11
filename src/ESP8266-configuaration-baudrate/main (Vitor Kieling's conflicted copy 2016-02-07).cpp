#include "mbed.h"

Serial pc(USBTX, USBRX);
Serial esp(PD0, PD1); // tx, rx

Timer t;

int  count,ended,timeout;
char buf[1024];
char snd[255];

char ssid[32] = "esp8266";     // enter router ssid inside the quotes
char pwd [32] = "emecstest"; // enter router password inside the quotes

void SendCMD(),getreply(),ESPconfig(),ESPsetbaudrate();

DigitalOut myled(LED1);

int main() {
    
	ESPsetbaudrate();

    pc.baud(115200);  // set what you want here depending on your terminal program speed
    esp.baud(9600);   // change this to the new ESP8266 baudrate if it is changed at any time.
    
       //******************  include this routine to set a different ESP8266 baudrate  ******************

    pc.printf("\n---------- AAAAAAAAAAAAAts ----------\r\n");


    //while(1) {
	myled = 1;
	wait(2);
	myled = 0;
	wait(2);
//}

    ESPconfig();        //******************  include Config to set the ESP8266 configuration  ***********************
    
	myled = 1;
	wait(5);
	myled = 0;
	wait(5);

   
   // contiuosly get AP list and IP
    while(1){
        pc.printf("\n---------- Listing Acces Points ----------\r\n");
        strcpy(snd, "AT+CWLAP\r\n");
        SendCMD();
        timeout=3;
        getreply();   
        pc.printf(buf);

        pc.printf("\n---------- Get IP's ----------\r\n"); 
        strcpy(snd, "AT+CIFSR\r\n");
        SendCMD();
        timeout=2;
        getreply(); 
        pc.printf(buf);
    }    
     
}

// Sets new ESP8266 baurate, change the esp.baud(xxxxx) to match your new setting once this has been executed
void ESPsetbaudrate()
{
    strcpy(snd, "AT+CIOBAUD=9600\r\n");   // change the numeric value to the required baudrate
    SendCMD();    
}    

//  +++++++++++++++++++++++++++++++++ This is for ESP8266 config only, run this once to set up the ESP8266 +++++++++++++++
void ESPconfig()
{

    pc.printf("---------- Starting ESP Config ----------\r\n\n");
    wait(2);
    pc.printf("---------- Reset & get Firmware ----------\r\n");
    strcpy(snd,"AT+RST\r\n");
    SendCMD();
    timeout=2;
    getreply();
    pc.printf(buf);
    
    wait(1);   
   
    pc.printf("\n---------- Get Version ----------\r\n");
    strcpy(snd,"AT+GMR\r\n");
    SendCMD();
    timeout=1;
    getreply();
    pc.printf(buf);    
    
    wait(1);
        
    // set CWMODE to 1=Station,2=AP,3=BOTH, default mode 1 (Station)
    pc.printf("\n---------- Setting Mode ----------\r\n");
    strcpy(snd, "AT+CWMODE=1\r\n");
    SendCMD();
    timeout=1;
    getreply();
    pc.printf(buf);
    
    wait(1);
    
    // set CIPMUX to 0=Single,1=Multi 
    pc.printf("\n---------- Setting Connection Mode ----------\r\n");
    strcpy(snd, "AT+CIPMUX=1\r\n"); 
    SendCMD();
    timeout=1;
    getreply();
    pc.printf(buf);
    
    wait(1);
    
    pc.printf("\n---------- Listing Acces Points ----------\r\n");
    strcpy(snd, "AT+CWLAP\r\n");
    SendCMD();
    timeout=3;
    getreply();   
    pc.printf(buf);
    
    wait(1);    
    
    pc.printf("\n---------- Connecting to AP ----------\r\n");
    pc.printf("ssid = %s   pwd = %s\r\n",ssid,pwd);
    strcpy(snd, "AT+CWJAP=\"");
    strcat(snd, ssid);
    strcat(snd, "\",\"");
    strcat(snd, pwd);
    strcat(snd, "\"\r\n");   
    SendCMD();
    timeout=8;
    getreply();    
    pc.printf(buf);
    
    wait(5);
    
    pc.printf("\n---------- Get IP's ----------\r\n"); 
    strcpy(snd, "AT+CIFSR\r\n");
    SendCMD();
    timeout=2;
    getreply(); 
    pc.printf(buf);
    
    wait(1);
    
    pc.printf("\n---------- Get Connection Status ----------\r\n"); 
    strcpy(snd, "AT+CIPSTATUS\r\n");
    SendCMD();
    timeout=2;
    getreply(); 
    pc.printf(buf);   
    
    pc.printf("\n\n\n  If you get a valid IP, ESP8266 has been set up.\r\n");
    pc.printf("  Run this if you want to reconfig the ESP8266 at any time.\r\n");
} 

void SendCMD()
{    
    esp.printf("%s", snd);    
} 

void getreply()
{    
    memset(buf, '\0', sizeof(buf));
    t.start();
    ended=0;count=0;
    while(!ended) {
        if(esp.readable()) {
            buf[count] = esp.getc();count++;
            }
        if(t.read() > timeout) {
                ended = 1;t.stop();t.reset();
            }
        }   
}              
 
