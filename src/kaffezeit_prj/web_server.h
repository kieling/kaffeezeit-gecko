/*
 * web_server.h
 *
 *  Created on: 04.02.2016
 *      Author: vitor
 */

#ifndef WEB_SERVER_H_
#define WEB_SERVER_H_

#include "mbed.h"

void SendCMD();
void getreply();
void ReadWebData();
void startserver();
void sendpage();
void SendWEB();
void sendcheck();

#endif /* WEB_SERVER_H_ */
