#include "Status.h"
using namespace std;

//c'tor for status
Status::Status()
{
	// current date and time on the current system
	time_t now = time(0);
	char *sTime = ctime(&now);
	if (sTime[strlen(sTime) - 1] == '\n')
		sTime[strlen(sTime) - 1] = '\0';
	dateTime = new char[strlen(sTime)+1];
	strcpy(dateTime, sTime);
}
void Status::updateTime(const char* newTime)
{
	delete[]dateTime;
	dateTime=strdup(newTime);
}
ostream& operator<<(ostream& os, const Status& status)
{
	os << strlen(status.dateTime) << " " << status.dateTime<<endl;
	status.toOs(os);
	return os;
}
void Status::showStatus() const
{
	cout << "|| wrote at: " << dateTime << endl;
}
Status::Status(const Status& other)
{
	*this = other;
}

Status::Status(Status&& other)
{
	*this = other;
	other.dateTime = nullptr;
}
const Status& Status:: operator=(Status&& other)
{
	if (this != &other)
	{ 
		std::swap(dateTime, other.dateTime);
		other.dateTime = nullptr;
	}
	return *this;
}
const Status& Status::operator=(const Status& other)
{
	if (this != &other)
	{
		delete[] dateTime;
		dateTime = strdup(other.dateTime);
	}
	return *this;
}
//d'tor for status
Status::~Status()
{
	delete[]dateTime;
}

