#include "mbed.h"

Serial pc(USBTX, USBRX);
Serial esp(PD4, PD5); // tx, rx

Timer t;

int  count,ended,timeout;
char buf[1024];
char snd[255];

char ssid[32] = "esp8266";     // enter router ssid inside the quotes
char pwd [32] = "test1234"; // enter router password inside the quotes

void SendCMD(),getreply(),ESPconfig(),ESPsetbaudrate();

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);

//DigitalOut bcEnablePin(PF7);
// PF7	PE0	PE1	UART0

int main() {

	//bcEnablePin = 0;

	//ESPsetbaudrate();

    pc.baud(115200);  // set what you want here depending on your terminal program speed
    esp.baud(115200);   // change this to the new ESP8266 baudrate if it is changed at any time.


  //  ESPsetbaudrate();

    ESPconfig();        //******************  include Config to set the ESP8266 configuration  ***********************

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
    strcpy(snd, "AT+CIOBAUD=115200\r\n");   // change the numeric value to the required baudrate
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

    myled2 = 1;


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

    wait(2);

    pc.printf("\n---------- Get IP STATUS ----------\r\n");
    strcpy(snd, "AT+CIPSTATUS\r\n");
    SendCMD();
    timeout=2;
    esp.printf("test");
    getreply();
    //pc.printf(buf);

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





//
//
//#include "mbed.h"
//
///*------------ Constant definitions --------------*/
//#define TX_PIN          USBTX
//#define RX_PIN          USBRX
//#define BRATE           115200
//
//#define LED_PIN         LED0
//#define TOGGLE_RATE     (0.5f)
//#define BUFF_LENGTH     5
//
///*-------- Check if platform compatible ----------*/
//#if DEVICE_SERIAL_ASYNCH
//Serial test_connection(USBTX, USBRX);
//#else
//#error "Platform not compatible with Low Power APIs for Serial"
//#endif
//
///*------------------ Variables -------------------*/
//LowPowerTicker      blinker;
//bool                blinking = false;
//event_callback_t    serialEventCb;
//DigitalOut          LED(LED_PIN);
//uint8_t             rx_buf[BUFF_LENGTH + 1];
//
///*------------------ Callbacks -------------------*/
//void blink(void) {
//    LED = !LED;
//}
//
///**
//* This is a callback! Do not call frequency-dependent operations here.
//*
//* For a more thorough explanation, go here:
//* https://developer.mbed.org/teams/SiliconLabs/wiki/Using-the-improved-mbed-sleep-API#mixing-sleep-with-synchronous-code
//**/
//void serialCb(int events) {
//    /* Something triggered the callback, either buffer is full or 'S' is received */
//    unsigned char i;
//    if(events & SERIAL_EVENT_RX_CHARACTER_MATCH) {
//        //Received 'S', check for buffer length
//        for(i = 0; i < BUFF_LENGTH; i++) {
//            //Found the length!
//            if(rx_buf[i] == 'S') break;
//        }
//
//        // Toggle blinking
//        if(blinking) {
//            blinker.detach();
//            blinking = false;
//        } else {
//            blinker.attach(blink, TOGGLE_RATE);
//            blinking = true;
//        }
//    } else if (events & SERIAL_EVENT_RX_COMPLETE) {
//        i = BUFF_LENGTH - 1;
//    } else {
//        rx_buf[0] = 'E';
//        rx_buf[1] = 'R';
//        rx_buf[2] = 'R';
//        rx_buf[3] = '!';
//        rx_buf[4] = 0;
//        i = 3;
//    }
//
//    // Echo string, no callback
//    test_connection.write(rx_buf, i+1, 0, 0);
//
//    // Reset serial reception
//    test_connection.read(rx_buf, BUFF_LENGTH, serialEventCb, SERIAL_EVENT_RX_ALL, 'S');
//}
//
///*-------------------- Main ----------------------*/
//int main() {
//    /* Very Simple Main (tm) */
//    serialEventCb.attach(serialCb);
//
//    /* Setup serial connection */
//    test_connection.baud(BRATE);
//    test_connection.printf("Low Power API test\n\nSend 'S' to toggle blinking\n");
//    test_connection.read(rx_buf, BUFF_LENGTH, serialEventCb, SERIAL_EVENT_RX_ALL, 'S');
//
//    /* Let the callbacks take care of everything */
//    while(1) sleep();
//}






