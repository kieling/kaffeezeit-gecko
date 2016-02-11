#include "mbed.h"

DigitalOut myled(LED1);

// Usb to PC ports
Serial pc(USBTX, USBRX);

// ESP8266ex wifi module TX and RX
Serial esp(PD0, PD1); // tx, rx

Timer t1;
Timer t2;

struct tm t;

int bufflen, DataRX, count, getcount, replycount, servreq, timeout;
int bufl, ipdLen, linkID, weberror, webcounter;
float temperature, AdcIn, Ht;
float R1=100000, R2=10000; // resistor values to give a 10:1 reduction of measured AnalogIn voltage
char Vcc[10];
char Temp[10];
char temp[10];
char webcount[8];
char lasthit[30];
char timebuf[30];
char type[16];
char type1[16];
char channel[2];
char cmdbuff[32];
char replybuff[512];
char webdata[1024]; // This may need to be bigger depending on WEB browser used
char webbuff[4096];     // Currently using 1986 characters, Increase this if more web page data added

void SendCMD(),getreply(),ReadWebData(),startserver(),sendpage(),SendWEB(),sendcheck();
void setRTC(),beep();

// manual set RTC values
int minute      =20;    // 0-59
int hour        =9;    // 2-23
int dayofmonth  =20;    // 1-31
int month       =2;     // 1-12
int year        =15;    // last 2 digits

int port        =8266;  // set server port
int SERVtimeout =5;    // set server timeout in seconds incase link breaks.

// Serial Interrupt read ESP data
void callback() {
    while (esp.readable()) {webbuff[count] = esp.getc();count++;}
    if(strlen(webbuff)>bufflen){DataRX=1;}
}

int main() {
    pc.baud(115200);
    esp.baud(115200);   // ESP8266 baudrate. Maximum on KLxx' is 115200, 230400 works on K20 and K22F

    if (time(NULL) < 1420070400) {setRTC();}

    blink();

    startserver();

    while(1){
        if(DataRX==1){
            ReadWebData();
            beep();
            if (servreq == 1 && weberror == 0){sendpage();}
            esp.attach(&callback);
            pc.printf(" IPD Data:\r\n\n Link ID = %d,\r\n IPD Header Length = %d \r\n IPD Type = %s\r\n", linkID, ipdLen, type);
            pc.printf("\n\n  HTTP Packet: \n\n%s\n", webdata);
            pc.printf("  Web Characters sent : %d\n\n", bufl);
            pc.printf("  -------------------------------------\n\n");
            strcpy(lasthit, timebuf);
            servreq=0;
        }
    }
}
// Static WEB page
void sendpage()
{
    gettime();

// WEB page data
    strcpy(webbuff, "<!DOCTYPE html>");
    strcat(webbuff, "<html><head><title>ESP8266 Mbed</title></head>");
    strcat(webbuff, "<body>");
    strcat(webbuff, "<div style=\"text-align:center; background-color:#F4F4F4; color:#00AEDB;\"><h1>ESP8266 Mbed Web Controller</h1>");
    strcat(webbuff, "Hit Count - ");
    strcat(webbuff, webcount);
    strcat(webbuff, "<br>Last Hit - ");
    strcat(webbuff, lasthit);
    strcat(webbuff, "</div><br /><hr>");
    strcat(webbuff, "<h3>Mbed RTC Time -&nbsp&nbsp");
    strcat(webbuff, timebuf);
    strcat(webbuff, "</h3>\r\n");
    strcat(webbuff, "<p><form method=\"POST\"><strong> Temperature:&nbsp&nbsp<input type=\"text\" size=6 value=\"");
    strcat(webbuff, Temp);
    strcat(webbuff, "\"> <sup>O</sup>C <form method=\"POST\"> <strong> &nbsp&nbspBattery:&nbsp&nbsp<input type=\"text\" size=4 value=\"");
    strcat(webbuff, Vcc);
    strcat(webbuff, "\"> </sup>V");
//    if(led1==1){strcat(webbuff, "<p><input type=\"radio\" name=\"led1\" value=\"0\" checked>  Red LED off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"led1\" value=\"1\" >  Red LED on");}
//        else{strcat(webbuff, "<p><input type=\"radio\" name=\"led1\" value=\"0\" >  Red LED off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"led1\" value=\"1\" checked>  Red LED on");}
//    if(Out1==0){strcat(webbuff, "<p><input type=\"radio\" name=\"Out1\" value=\"0\" checked>  Digital Out 1  off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out1\" value=\"1\" >  Digital Out 1 on");}
//        else{strcat(webbuff, "<p><input type=\"radio\" name=\"Out1\" value=\"0\" >  Digital Out 1 off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out1\" value=\"1\" checked>  Digital Out 1 on");}
//    if(Out2==0){strcat(webbuff, "<p><input type=\"radio\" name=\"Out2\" value=\"0\" checked>  Digital Out 2 off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out2\" value=\"1\" >  Digital Out 2 on");}
//        else{strcat(webbuff, "<p><input type=\"radio\" name=\"Out2\" value=\"0\" >  Digital Out 2 off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out2\" value=\"1\" checked>  Digital Out 2 on");}
//    if(Out3==0){strcat(webbuff, "<p><input type=\"radio\" name=\"Out3\" value=\"0\" checked>  Digital Out 3 off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out3\" value=\"1\" >  Digital Out 3 on");}
//        else{strcat(webbuff, "<p><input type=\"radio\" name=\"Out3\" value=\"0\" >  Digital Out 3 off");
//                strcat(webbuff, "<br><input type=\"radio\" name=\"Out3\" value=\"1\" checked>  Digital Out 3 on");}
//    if(In1==0){strcat(webbuff, "<p><input type=\"radio\" name=\"In1\" value=\"0\" >  Digital In 1");}
//        else{strcat(webbuff, "<p><input type=\"radio\" name=\"In1\" value=\"1\" checked>  Digital In 1");}
//    if(In2==0){strcat(webbuff, "<br><input type=\"radio\" name=\"In2\" value=\"0\" >  Digital In 2");}
//        else{strcat(webbuff, "<br><input type=\"radio\" name=\"In2\" value=\"1\" checked>  Digital In 2");}
//    if(In3==0){strcat(webbuff, "<br><input type=\"radio\" name=\"In3\" value=\"0\" >  Digital In 3");}
//        else{strcat(webbuff, "<br><input type=\"radio\" name=\"In3\" value=\"1\" checked>  Digital In 3");}
    strcat(webbuff, "</strong><p><input type=\"submit\" value=\"send-refresh\" style=\"background: #3498db;");
    strcat(webbuff, "background-image:-webkit-linear-gradient(top, #3498db, #2980b9);");
    strcat(webbuff, "background-image:linear-gradient(to bottom, #3498db, #2980b9);");
    strcat(webbuff, "-webkit-border-radius:12;border-radius: 12px;font-family: Arial;color:#ffffff;font-size:20px;padding:");
    strcat(webbuff, "10px 20px 10px 20px; border:solid #103c57 3px;text-decoration: none;");
    strcat(webbuff, "background: #3cb0fd;");
    strcat(webbuff, "background-image:-webkit-linear-gradient(top,#3cb0fd,#1a5f8a);");
    strcat(webbuff, "background-image:linear-gradient(to bottom,#3cb0fd,#1a5f8a);");
    strcat(webbuff, "text-decoration:none;\"></form></span>");
    strcat(webbuff, "<p/><h2>How to use:</h2><ul>");
    strcat(webbuff, "<li>Select the Radio buttons to control the digital out pins.</li>");
    strcat(webbuff, "<li>Click 'Send-Refresh' to send.</li>");
    strcat(webbuff, "<li>Use the 'Send-Refresh' button to refresh the data.</li>");
    strcat(webbuff, "</ul>");
    strcat(webbuff, "</body></html>");
// end of WEB page data
    bufl = strlen(webbuff); // get total page buffer length
    sprintf(cmdbuff,"AT+CIPSEND=%d,%d\r\n", linkID, bufl); // send IPD link channel and buffer character length.
    timeout=200;getcount=7;
    SendCMD();
    getreply();
    SendWEB();  // send web page
    memset(webbuff, '\0', sizeof(webbuff));
    sendcheck();
}

//  wait for ESP "SEND OK" reply, then close IP to load web page
void sendcheck()
{
     weberror=1;timeout=500;getcount=24;
    t2.reset();t2.start();
    while(weberror==1 && t2.read() <5){
        getreply();
        if (strstr(replybuff, "SEND OK") != NULL) {weberror=0;}  // wait for valid SEND OK
        }
    if(weberror==1){ // restart connection
        strcpy(cmdbuff, "AT+CIPMUX=1\r\n");
        timeout=500;getcount=10;
        SendCMD();getreply();
        sprintf(cmdbuff,"AT+CIPSERVER=1,%d\r\n", port);
        timeout=500;getcount=10;
        SendCMD();getreply();
        }
        else{
            sprintf(cmdbuff, "AT+CIPCLOSE=%s\r\n",channel); // close current connection
            SendCMD();}
    t2.reset();
}

// Reads and processes GET and POST web data
void ReadWebData()
 {
    wait_ms(200);
    esp.attach(NULL);
    count=0;DataRX=0;weberror=0;
    memset(webdata, '\0', sizeof(webdata));
    int x = strcspn (webbuff,"+");
    if(x){
        strcpy(webdata, webbuff + x);weberror=0;
        int numMatched = sscanf(webdata,"+IPD,%d,%d:%s", &linkID, &ipdLen, type);
//        if( strstr(webdata, "led1=1") != NULL ) {led1=0;}
//        if( strstr(webdata, "led1=0") != NULL ) {led1=1;}
//        if( strstr(webdata, "Out1=1") != NULL ) {Out1=1;}
//        if( strstr(webdata, "Out1=0") != NULL ) {Out1=0;}
//        if( strstr(webdata, "Out2=1") != NULL ) {Out2=1;}
//        if( strstr(webdata, "Out2=0") != NULL ) {Out2=0;}
//        if( strstr(webdata, "Out3=1") != NULL ) {Out3=1;}
//        if( strstr(webdata, "Out3=0") != NULL ) {Out3=0;}
        sprintf(channel, "%d",linkID);
        if (strstr(webdata, "GET") != NULL) {servreq=1;}
        if (strstr(webdata, "POST") != NULL) {servreq=1;}
        webcounter++;
        sprintf(webcount, "%d",webcounter);
        }
            else {
                memset(webbuff, '\0', sizeof(webbuff));
                esp.attach(&callback);weberror=1;
                }
}

// Starts and restarts webserver if errors detected.
void startserver()
{
    gettime();
    pc.printf("\n\n RTC time   %s\r\n\n",timebuf);
    pc.printf("++++++++++ Resetting ESP ++++++++++\r\n");
    strcpy(cmdbuff,"AT+RST\r\n");
    timeout=2000;getcount=600;
    SendCMD();
    getreply();
    pc.printf(replybuff);
    pc.printf("%d",count);

    if (strstr(replybuff, "OK") != NULL) {
        pc.printf("\n++++++++++ Starting Server ++++++++++\r\n");
        strcpy(cmdbuff, "AT+CIPMUX=1\r\n");  // set multiple connections.
        timeout=500;getcount=10;
        SendCMD();
        getreply();
        sprintf(cmdbuff,"AT+CIPSERVER=1,%d\r\n", port);
        timeout=500;getcount=10;
        SendCMD();
        getreply();
        sprintf(cmdbuff,"AT+CIPSTO=%d\r\n",SERVtimeout);
        timeout=500;getcount=50;
        SendCMD();
        getreply();
        pc.printf("\n Getting Server IP \r\n");
        strcpy(cmdbuff, "AT+CIFSR\r\n");
        timeout=1000;getcount=50;
        while(weberror==0){
            SendCMD();getreply();
            if (strstr(replybuff, "0.0.0.0") == NULL) {weberror=1;}  // wait for valid IP
            }
        pc.printf("\n Enter WEB address in your browser \r\n\n");
        replybuff[strlen(replybuff) - 8] = '\0';
        char* IP = replybuff + 5;
        sprintf(webdata,"   http://%s:%d", IP, port);
        pc.printf(webdata);

//        led2=0;wait(2);led2=1;

        bufflen=200;count=0;
        pc.printf("\n\n++++++++++ Ready ++++++++++\r\n\n");
        esp.attach(&callback);
        }
        else{
            pc.printf("\n++++++++++ ESP8266 error, check power/connections ++++++++++\r\n");
            while(1){}
            }
        t2.reset();t2.start();beep();
}

// ESP Command data send
void SendCMD()
{
    esp.printf("%s", cmdbuff);
}

// Large WEB buffer data send
void SendWEB()
{
    int i=0;
    if(esp.writeable()) {
        while(webbuff[i]!='\0') {esp.putc(webbuff[i]);i++;}
        }
}

// Get Command and ESP status replies
void getreply()
{
    memset(replybuff, '\0', sizeof(replybuff));
    t1.reset(); t1.start();replycount=0;
    while(t1.read_ms()< timeout && replycount < getcount) {
        if(esp.readable()) {
            replybuff[replycount] = esp.getc();replycount++;
            }
        }
    t1.stop();
}

// Get RTC time
void gettime()
{
    time_t seconds = time(NULL);
    strftime(timebuf,50,"%H:%M:%S %a %d %b %y", localtime(&seconds));
}

void blink()
{
   while(1) {
		myled = 1;
		wait(0.2);
		myled = 0;
		wait(0.2);
	}
}

void setRTC()
{
            t.tm_sec = (0);             // 0-59
            t.tm_min = (minute);        // 0-59
            t.tm_hour = (hour);         // 0-23
            t.tm_mday = (dayofmonth);   // 1-31
            t.tm_mon = (month-1);       // 0-11  "0" = Jan, -1 added for Mbed RCT clock format
            t.tm_year = ((year)+100);   // year since 1900,  current DCF year + 100 + 1900 = correct year
            set_time(mktime(&t));       // set RTC clock
}
