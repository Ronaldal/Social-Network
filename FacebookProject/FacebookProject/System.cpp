#include "System.h"
using namespace std;

//constractor 
//here we allocate all the entities arrays.
System::System()
{
}
//in this function we init the system from the file we create.
// we get all the members array size and than for each member we get its birthday, his name, and adding him his friends and statuses.
void System::initSystem()
{
	ifstream inFile("system.txt");
	int memberArraySize, fanPageArraySize;
	inFile >> memberArraySize;
	Date d;
	string name, secName;
	for (int i = 0; i < memberArraySize; i++)
	{
		inFile >> d;
		inFile.ignore();
		getline(inFile, name);
		this->addMember(d, name);
		inFile >> *allMembersArr[i];
	}
	inFile >> fanPageArraySize;
	inFile.ignore();
	for (int i = 0; i < fanPageArraySize; i++)
	{
		getline(inFile, name);
		this->addFanPage(name);
		inFile >> *allFanPagesArr[i];
	}

	for (int i = 0; i < memberArraySize; i++)
	{
		getline(inFile, name);
		int numOfFriends;
		inFile >> numOfFriends;
		inFile.ignore();
		for (int j = 0; j < numOfFriends; j++)
		{
			getline(inFile, secName);
			int PlaceOfMemberToAdd = isMemberAlreadyExistWithExc(secName);
			if (!((allMembersArr[i])->isFriendsAlready(allMembersArr[PlaceOfMemberToAdd])))
				*(allMembersArr[i]) += *(allMembersArr[PlaceOfMemberToAdd]);
		}
		int numOfFanPages;
		inFile >> numOfFanPages;
		inFile.ignore();
		for (int j = 0; j < numOfFanPages; j++)
		{
			getline(inFile, secName);
			int placeOfFanPage = isFanPageAlreadyExistWithExc(secName);
			*(allFanPagesArr[placeOfFanPage]) += *(allMembersArr[i]);
			*(allMembersArr[i]) += *(allFanPagesArr[placeOfFanPage]);
		}
	}
	inFile.close();
}
//in this function we add a member to the the all members array using the logical physical algorithem.
//return true if the add success.
void System::addMember(const Date& birthDate, const string& name) throw(MemberException)
{
	if (isMemberAlreadyExist(name) == NOT_FOUND)
	{
		Member* m = new Member(name, birthDate);
		if (allMembersArr.size() == allMembersArr.capacity())
		{
			allMembersArr.reserve(allMembersArr.size() * 2);
		}
		allMembersArr.push_back(m);
	}
	else
		throw (MemberException());

}

//this function check if the fan page already exist in the system.
//if so, returns the index of the fan page in the array, otherwise returns false.
int System::isFanPageAlreadyExist(const string& name) const
{
	int i = 0;
	for (auto s : allFanPagesArr)
	{
		if (name == s->getFanPageName())
			return i;
		i++;
	}
	return NOT_FOUND;
}
int System::isFanPageAlreadyExistWithExc(const string& name) const throw(FanPageNotExistException)
{
	int i = 0;
	for (auto s : allFanPagesArr)
	{
		if (name == s->getFanPageName())
			return i;
		i++;
	}
	throw (FanPageNotExistException());
}
//this function check if the member already exist in the system.
//if so, returns the index of the member in the array, otherwise returns false.
int System::isMemberAlreadyExist(const string& name) const
{
	int i = 0;
	for (auto s : allMembersArr)
	{
		if (name == s->getMemberName())
			return i;
		i++;
	}
	return NOT_FOUND;
}
int System::isMemberAlreadyExistWithExc(const string& name) const throw(MemberNotExistException)
{
	int i = 0;
	for (auto s : allMembersArr)
	{
		if (name == s->getMemberName())
			return i;
		i++;
	}
	throw MemberNotExistException();
}
//this method add fan page to system.
void System::addFanPage(const string& name) throw (FanPageException)
{
	if (isFanPageAlreadyExist(name) == NOT_FOUND)
	{
		FanPage* m = new FanPage(name);
		if (allFanPagesArr.size() == allFanPagesArr.capacity())
		{
			allFanPagesArr.reserve(allFanPagesArr.size() * 2);
		}
		allFanPagesArr.push_back(m);
	}
	else
		throw(FanPageException());

}
//after we ask for the specific status type from the member we allocate the relevant status.
Status* System::getStatus(int statusType, const string& statusToAdd)throw(StatusTypeException)
{
	Status* status = nullptr;
	switch (statusType)
	{
	case TEXT:
		status = new TextStatus(statusToAdd);
		break;
	case VIDEO:
		status = new VideoStatus(statusToAdd);
		break;
	case PICTURE:
		status = new PictureStatus(statusToAdd);
		break;
	default:
		throw StatusTypeException();
	}
	return status;
}
//adding status to member by its relevant type.
void System::addStatus(const string& name, const string& statusToAdd, int statusType) noexcept (false)
{
	int place = isMemberAlreadyExistWithExc(name);
	Status* newStatus = getStatus(statusType, statusToAdd);
	allMembersArr[place]->addStatus(newStatus);

}

void System::addStatusToFanPage(const string& name, const string& statusToAdd, int statusType)noexcept (false)
{
	int place = isFanPageAlreadyExistWithExc(name);
	Status* newStatus = getStatus(statusType, statusToAdd);
	allFanPagesArr.at(place)->addStatus(newStatus);
}
void System::showStatusesOfMember(const string& name) const noexcept (false)
{
	int place = isMemberAlreadyExistWithExc(name);
	allMembersArr.at(place)->printAllStatus();

}

void System::showStatusesOfFanPage(const string& name) const noexcept (false)
{
	int place = isFanPageAlreadyExistWithExc(name);
	allFanPagesArr.at(place)->printAllStatus();

}

void System::showLast10Statuses(const string& name) const noexcept(false)
{
	int place = isMemberAlreadyExistWithExc(name);
	allMembersArr.at(place)->printLast10Status();
}

void System::friendShipLinkBetweenTwoMembers(const string& name, const string& nameOfmemberToAdd) noexcept (false)
{
	int placeOfFirstMember = isMemberAlreadyExistWithExc(name);
	int PlaceOfMemberToAdd = isMemberAlreadyExistWithExc(nameOfmemberToAdd);
	*(allMembersArr[placeOfFirstMember]) += *(allMembersArr[PlaceOfMemberToAdd]);
}
void System::deleteFriendShipBetweenTwoMembers(const string& nameOfFirstMember, const string& nameOfMemberToRemove)noexcept(false)
{
	int placeOfFirstMember = isMemberAlreadyExistWithExc(nameOfFirstMember);
	int PlaceOfMemberToRemove = isMemberAlreadyExistWithExc(nameOfMemberToRemove);
	(allMembersArr[placeOfFirstMember]->removeMember(allMembersArr[PlaceOfMemberToRemove]));
}
void System::addMemberToFanPage(const string& fanPageName, const string& memberToAdd)noexcept(false)
{
	int placeOfFanPage = isFanPageAlreadyExistWithExc(fanPageName);
	int PlaceOfMember = isMemberAlreadyExistWithExc(memberToAdd);
	*(allFanPagesArr[placeOfFanPage]) += *(allMembersArr[PlaceOfMember]);
	*(allMembersArr[PlaceOfMember]) += *(allFanPagesArr[placeOfFanPage]);
}
void System::deleteMemberFromFanPage(const string& fanPageName, const string& nameOfMemberToRemove)throw(FanPageFollowException)
{
	int placeOfFanPage = isFanPageAlreadyExistWithExc(fanPageName);
	int PlaceOfMemberToRemove = isMemberAlreadyExistWithExc(nameOfMemberToRemove);
	if (!allFanPagesArr[placeOfFanPage]->deleteMemberFromFanPage(allMembersArr[PlaceOfMemberToRemove]))
		throw FanPageFollowException();

}
void System::showMembers() const
{
	int i = 1;
	for (auto member : allMembersArr)
	{
		cout << i << ".";
		member->showMemberName();
		i++;
	}
}
void System::showFanPages() const
{
	int i = 1;
	for (auto FanPage : allFanPagesArr)
	{
		cout << i << ".";
		FanPage->printName();
		i++;
	}
}
void System::showAllFriendsOfMember(const string& name) const noexcept (false)
{
	int placeOfMember = isMemberAlreadyExistWithExc(name);
	allMembersArr[placeOfMember]->showMemberFriends();
}
void System::showAllFollowersOfFanPage(const string& name) const noexcept (false)
{
	int placeOfFanPage = isFanPageAlreadyExistWithExc(name);
	allFanPagesArr[placeOfFanPage]->showMembersOfFanPage();

}
//in this function we create the file with all the members, fan pages and their connections.
void System::createFile() const
{
	ofstream outFile("system.txt", ios::trunc);
	outFile << allMembersArr.size() << endl;
	for (auto member : allMembersArr)
	{
		outFile << *member;
	}
	outFile << allFanPagesArr.size() << endl;
	for (auto FanPage : allFanPagesArr)
	{
		outFile << *FanPage;
	}
	for (auto member : allMembersArr)
	{
		member->saveConnections("system.txt");
	}

	outFile.close();
}
//d'tor
System::~System()
{
	for (auto member : allMembersArr)
		delete member;
	for (auto FanPage : allFanPagesArr)
		delete FanPage;

}