/*
 * User.h
 *
 *  Created on: 05.02.2016
 *      Author: vitor
 */
#include <iostream>
#include <string>
#include <string.h>

#ifndef LOGTYPE_H_
#define LOGTYPE_H_

using namespace std;

class LogType {

public:
	string name;
	string ip;
	string rfid;
	char timebuff[30];

	LogType(string name_, string ip_, string rfid_, char *timebuff_){
		name = name_;
		rfid = rfid_;
		ip = ip_;
		strcpy(timebuff, timebuff_);
	}

	~LogType();
};

#endif /* USER_H_ */
