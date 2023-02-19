#include <fstream>
#include <string.h>
#include <string>
#include <iostream>
#ifndef __STATUS_H
#define __STATUS_H
using namespace std;
#pragma warning (disable: 4996)
#include <ctime>
#include <vector>
#include <sstream>

//The status class is for using the statuses in the program. 
//The dateTime string is for saving the time the status written.
class Status
{
protected:
	char * dateTime;
public:
	Status();
	virtual void showStatus() const;
	const Status& operator=(const Status& other);
	Status(Status&& other);
	void updateTime(const char* newTime);
	const Status& operator=(Status&& other);
	Status(const Status& other);
	virtual void toOs(ostream& os)const{}
	friend ostream& operator<<(ostream& os, const Status& status);
	virtual ~Status();
	virtual Status* clone() const = 0;
};

#endif // !__STATUS_H
