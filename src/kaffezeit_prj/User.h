/*
 * User.h
 *
 *  Created on: 05.02.2016
 *      Author: vitor
 */
#include <iostream>
#include <string>

#ifndef USER_H_
#define USER_H_

using namespace std;

class User {

public:
	string name;
	string ip;
	string rfid;
	int coffeeCount;

	User(string name_, string ip_, int coffeeCount_, string rfid_){
		rfid = rfid_;
		coffeeCount = coffeeCount_;
		name = name_;
		ip = ip_;
	}

	~User();
};

#endif /* USER_H_ */
