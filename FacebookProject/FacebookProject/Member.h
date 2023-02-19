#ifndef __MEMBER_H
#define __MEMBER_H
#include "BillBoard.h"
#include "Date.h"

class FanPage;

//the class member contains the member name, his birth of date,
//his members in array, the fan pages he like in array and the meber statuses.
class Member
{
private:
	string name;
	const Date birthDate;
	BillBoard memberBillBoard;
	vector<Member*> memberFriends;
	vector<FanPage*> fanPageTheMemberLike;

public:

	Member(const string& name , const Date& birthDate);
	Member(const Member& other) = delete;
	Member(const Member&& other) = delete;
	void removeMember( Member* memberToRemove)throw (RemoveMemberException);
	bool removeMemberHalper(Member* memberToRemove);
	bool removeFanPage(FanPage* fanPageToRemove);

	void showFanPagesMemberLike() const;
	void showMemberName() const;
	void showMemberFriends() const;

	const string& getMemberName() const;
	void addStatus(Status* statusToAdd);

	void printLast10Status() const;
	void printAllStatus() const;
	int getMemberFriendsArrSize() const;
	bool isFriendsAlready(const Member* memberToAdd) const;
	bool pageLikedAlreadyByMember(FanPage* fanPageToAdd) const;
	bool operator!=(const Member& other);
	bool operator==(const Member& other);
	const Member& operator+=(Member& other)throw (AddMemberException);
	const Member& operator+=(FanPage& other) throw (AddFanPageException);
	bool operator>(const Member& other)const;
	bool operator>(const FanPage& other)const;
	friend ostream& operator<<(ostream& os, const Member& member);
	friend istream& operator>>(istream& in, Member& member);
	void saveConnections(const string& fileName) const;
	~Member();

};
#endif // !__MEMBER_H
