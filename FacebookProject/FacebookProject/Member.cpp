#include "Member.h"
#include "fanPage.h"
using namespace std;

//c'tor for member.
//in this method we allocate the member friends array and the fan pages array he like.
Member::Member(const string& name, const Date& birthDate) :name(name), birthDate(birthDate)
{
}

const string& Member::getMemberName() const
{
	return name;
}

//The function gets a member and returns true if the member to be added is in the member array else returns false
bool Member::isFriendsAlready(const Member* memberToAdd) const
{

	for (auto& s : memberFriends)
	{
		if (*s == *memberToAdd)
			return true;
	}
	return false;
}

bool Member::pageLikedAlreadyByMember(FanPage* fanPageToAdd) const
{

	for (auto s : fanPageTheMemberLike)
	{
		if (*s == *fanPageToAdd)
			return true;
	}
	return false;
}

//The function gets a member and removes him from the array  
void Member::removeMember(Member* memberToRemove) throw (RemoveMemberException)
{
	if (this->removeMemberHalper(memberToRemove))
		memberToRemove->removeMemberHalper(this);//mutual 
	else
		throw RemoveMemberException();
}

bool Member::removeMemberHalper(Member* memberToRemove)
{
	vector<Member*>::iterator itr = memberFriends.begin();
	vector<Member*>::iterator itrEnd = memberFriends.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == memberToRemove)
		{
			memberFriends.erase(itr);
			return true;
		}
	}
	return false;
}

//this method remove a fan page from member.
bool Member::removeFanPage(FanPage* fanPageToRemove)
{
	vector<FanPage*>::iterator itr = fanPageTheMemberLike.begin();
	vector<FanPage*>::iterator itrEnd = fanPageTheMemberLike.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == fanPageToRemove)
		{
			fanPageTheMemberLike.erase(itr);
			fanPageToRemove->deleteMemberFromFanPage(this);//mutual
			return true;
		}
	}
	return false;
}

void Member::addStatus(Status* statusToAdd)
{
	memberBillBoard.addStatus(statusToAdd);
}

void Member::printLast10Status() const
{
	vector<Member*>::const_iterator itr = memberFriends.begin();
	vector<Member*>::const_iterator itrEnd = memberFriends.end();
	for (int i = 1; itr != itrEnd; i++, ++itr)
	{
		cout << i << ". " << (*itr)->name << "'s statuses are:" << endl;
		(*itr)->memberBillBoard.showMemberBillboard();
	}
}

void Member::printAllStatus() const
{
	memberBillBoard.showBillBoard();
}

void Member::showMemberFriends() const
{
	cout << "Member name:" << name << endl;
	cout << "His Friends: " << endl;
	int i = 1;
	for (auto s : memberFriends)
	{
		cout << i << ". " << s->name << endl;
		i++;
	}
}

void Member::showMemberName() const
{
	cout << name << endl;
}

void Member::showFanPagesMemberLike() const
{
	cout << "Member name: " << name << endl;
	cout << "The fan pages he/she like: " << endl;
	int i = 1;
	for (auto s : fanPageTheMemberLike)
	{
		cout << i << ".";
		s->printName();
		i++;
	}
}
//operator overloading for member in order to print its name, birth date and his billboard.
ostream& operator<<(ostream& os, const Member& member)
{
	os << member.birthDate << endl;
	os << member.name << endl;
	os << member.memberBillBoard;
	return os;
}
istream& operator>>(istream& in, Member& member)
{
	in >> member.memberBillBoard;
	return in;
}
//in this function we print to the file each member and his relevant friends, the same with fan page.
void Member::saveConnections(const string& fileName) const
{
	ofstream outFile(fileName, ios::app);
	outFile << name << endl;
	outFile << memberFriends.size() << endl;
	for (auto member : memberFriends)
	{
		outFile << (*member).name << endl;
	}
	outFile << fanPageTheMemberLike.size() << endl;
	for (auto fanPage : fanPageTheMemberLike)
	{
		outFile << fanPage->getFanPageName() << endl;
	}
}


Member::~Member()
{

}

const Member& Member:: operator+=(FanPage& other) throw (AddFanPageException)
{
	if (!pageLikedAlreadyByMember(&other))
	{
		if (fanPageTheMemberLike.size() == fanPageTheMemberLike.capacity())
			fanPageTheMemberLike.reserve(fanPageTheMemberLike.size() * 2);

		fanPageTheMemberLike.push_back(&other);
	}
	else
	{
		throw AddFanPageException();
	}
	return *this;
}
const Member& Member::operator+=(Member& other) throw (AddMemberException)
{
	if (!isFriendsAlready(&other) && (*this != other))//First we check if the member is already friend
	{
		if (memberFriends.size() == memberFriends.capacity())
			memberFriends.reserve(memberFriends.size() * 2);

		memberFriends.push_back(&other);

		/*Because the membership is mutual,
		we will add the friend who activated the function to the friend who needs to be added*/
		if (other.memberFriends.size() == other.memberFriends.capacity())
			other.memberFriends.reserve(other.memberFriends.size() * 2);

		other.memberFriends.push_back(this);
	}
	else
	{
		throw(AddMemberException());
	}

	return (*this);
}
bool Member::operator>(const Member& other)const
{
	return (memberFriends.size() > other.memberFriends.size() ? true : false);
}
bool Member::operator>(const FanPage& other)const
{

	return (memberFriends.size() > other.getFanPageMemberArrSize() ? true : false);
}
int Member::getMemberFriendsArrSize() const
{
	return memberFriends.size();
}

bool Member::operator==(const Member& other)
{
	return(name == other.name ? true : false);
}
bool Member::operator!=(const Member& other)
{
	return!(*this == other);
}