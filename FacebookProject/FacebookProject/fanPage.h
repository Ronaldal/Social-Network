#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "BillBoard.h"
#include "Exceptions.h"
class Member;//forward declartion

//The class fan page contains the name of the fan page, 
//the members whom liked the fan page
//and the billboard which contains the statuses array.

class FanPage
{
	string name;
	vector<Member*> fanPageMembers;
	BillBoard fanPageBillBoard;
public:
	FanPage(const string& name);
	FanPage(const FanPage& other) = delete;
	FanPage(const FanPage&& other) = delete;
	bool deleteMemberFromFanPage(Member* memberToDelete);

	void showMembersOfFanPage() const;
	const string& getFanPageName() const;
	void printName() const;

	bool pageLikedAlreadyByMember(Member* memberToAdd) const;
	void addStatus(Status* statusToAdd);
	void printAllStatus() const;
	int getFanPageMemberArrSize() const;
	bool operator!=(const FanPage& other);
	bool operator==(const FanPage& other);
	const FanPage& operator+=(Member& other) throw(AddMemberException);
	friend ostream& operator<<(ostream& os, const FanPage& fanPage);
	friend istream& operator>>(istream& in, FanPage& fanPage);
	bool operator> (const Member& other)const;
	bool operator>(const FanPage& other)const;

	~FanPage();

	

};
#endif // __FANPAGE_H
