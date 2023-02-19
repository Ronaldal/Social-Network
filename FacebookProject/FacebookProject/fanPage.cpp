#include "fanPage.h"
#include "Member.h"
using namespace std;

//c'tor
FanPage::FanPage(const string& name): name(name)
{
}
//operator overloading for fan page.
//print its name and his billboard.
ostream& operator<<(ostream& os, const FanPage& fanPage)
{
	os << fanPage.name << endl;
	os << fanPage.fanPageBillBoard;
	return os;
}
//operator overloading for fan page.
//get fan page billboard
istream& operator>>(istream& in, FanPage& fanPage)
{
	in >> fanPage.fanPageBillBoard;
	return in;
}
int FanPage::getFanPageMemberArrSize()const
{
	return fanPageMembers.size();
}
//this method delete member from fan page.
//return true if the member succesfuly removed.
bool FanPage::deleteMemberFromFanPage(Member* memberToDelete)
{
	vector<Member*>::iterator itr = fanPageMembers.begin();
	vector<Member*>::iterator itrEnd = fanPageMembers.end();

	for (; itr != itrEnd; ++itr)
	{
		if (*itr == memberToDelete)
		{
			fanPageMembers.erase(itr);
			/*Because the membership is mutual,
			we will remove the friend who activated the function to the friend who needs to be removed*/
			memberToDelete->removeFanPage(this);
			return true;
		}
	}
	return false;
}
//compaers between fan page and member.
bool FanPage:: operator> (const Member& other)const
{
	return (fanPageMembers.size() > other.getMemberFriendsArrSize() ? true : false);
}
bool FanPage:: operator>(const FanPage& other)const
{
	return (fanPageMembers.size() > other.fanPageMembers.size() ? true : false);
}
//method to check if the page liked already by member.
bool FanPage::pageLikedAlreadyByMember(Member* memberToAdd) const
{
	for (auto s: fanPageMembers)
	{
		if (*s == *memberToAdd)
		{
			return true;
		}
	}
	return false;
}

//add member to fan page.
const FanPage& FanPage::operator+=(Member& other) throw(AddMemberException)
{
	if (!pageLikedAlreadyByMember(&other))//add only if the member doesnt exist
	{
		if (fanPageMembers.size() == fanPageMembers.capacity())
			fanPageMembers.reserve(fanPageMembers.size() * 2);
		
		fanPageMembers.push_back(&other);
	}
	else
	{
		throw AddMemberException();
	}
	return *this;
}

//print the members who liked certain fan page.
void FanPage::showMembersOfFanPage() const
{
	cout << "Fan page name :" << name << endl;
	cout <<"Liked by:" << endl;
	int i = 1;
	for (auto s : fanPageMembers)
	{
		cout <<i<< ". ";
		s->showMemberName();
		i++;
	}
}

void FanPage::addStatus(Status* statusToAdd)
{
	fanPageBillBoard.addStatus(statusToAdd);
}
void FanPage::printAllStatus() const
{
	fanPageBillBoard.showBillBoard();
}
void FanPage::printName() const
{
	cout << name << endl;
}
//d'tor
FanPage::~FanPage()
{

}

bool FanPage::operator==(const FanPage& other)
{
	return(name==other.name ? true : false);
}
bool FanPage::operator!=(const FanPage& other)
{
	return!(*this == other);
}
const string& FanPage::getFanPageName() const
{
	return name;
}