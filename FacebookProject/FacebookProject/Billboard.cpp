#include "BillBoard.h"

//c'tor
BillBoard::BillBoard()
{
}
// in this function we get the input from the text by order we decided ahead.
//first we get the number of statuses and than we are running in for loop in order to get every status and its creation time
istream& operator>>(istream& in, BillBoard& billboard)
{
	int numOfStatuses, lenTime;
	char *time;
	string statusType, statusData;
	Status* statusToAdd;
	in >> numOfStatuses;
	for (int i = 0; i < numOfStatuses; i++)
	{
		in >> statusType;
		in >> lenTime;
		time = new char[lenTime+1];
		in.ignore();
		in.getline(time, lenTime + 1);
		getline(in, statusData);

		//allocate the status by its relevant type.
		if (statusType == (typeid(TextStatus).name() + 6))
			statusToAdd = new TextStatus(statusData);
		else if (statusType == (typeid(VideoStatus).name() + 6))
			statusToAdd = new VideoStatus(statusData);
		else
			statusToAdd = new PictureStatus(statusData);

		statusToAdd->updateTime(time);
		billboard.addStatus(statusToAdd);
	}
	return in;
}
//print the output  from the member billboard to the file.
ostream& operator<<(ostream& os, const BillBoard& billboard)
{
	os << billboard.statusArr.size() << endl;
	for (auto status : billboard.statusArr)
	{
		os << typeid(*(status)).name() + 6 << " " << *status<<endl;
	}
	return os;
}

// this function adding status to the statuses array of entity.
//because there isnt size to the array we using the logical physical algorythem.
void BillBoard::addStatus( Status* statusToAdd)
{
	if (statusArr.size() == statusArr.capacity())
	{
		statusArr.reserve(statusArr.size() * 2);
	}

	statusArr.push_back(statusToAdd);
}

// function for print the last 10 statuses of member.
void BillBoard::showMemberBillboard() const
{
	vector<Status*>::const_iterator itr = statusArr.begin();
	vector<Status*>::const_iterator itrEnd = statusArr.end();

	if (statusArr.size() < 10)
	{
		for (; itr != itrEnd; itr++)
		{
			(*itr)->showStatus();
		}
	}
	else
	{
		itr = itrEnd - 10;
		for (; itr < itrEnd; itr++)
		{
			(*itr)->showStatus();
		}
	}
}
void BillBoard::showBillBoard() const
{
	vector<Status*>::const_iterator itr = statusArr.begin();
	vector<Status*>::const_iterator itrEnd = statusArr.end();
	for (; itr!=itrEnd; itr++)
	{
		(*itr)->showStatus();
	}
}

//d'tor for free every status and the array itself.
BillBoard::~BillBoard()
{
	for (auto s : statusArr)
	{
		delete s;
	}
}



