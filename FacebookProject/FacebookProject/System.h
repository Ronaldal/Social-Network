#ifndef __SYSTEM_H
#define __SYSTEM_H

#define NOT_FOUND -1
#include "fanPage.h"
#include "Member.h"
#define MEMBER 'M'
enum userChoose {ADD_MEMBER = 1,ADD_FAN_PAGE,ADD_STATUS,SHOW_STATUSES
	,SHOW_10_STATUSES,LINK_FRIENDS,DELETE_FRIENSHIP,ADD_MEMBER_TO_FAN_PAGE,
	DELETE_MEMBER_FROM_FAN_PAGE,SHOW_ALL_ENTITIES,SHOW_ALL_FRIENDS_OR_FOLLOWERS,EXIT};

enum statusType {TEXT=1,VIDEO,PICTURE};
//the class system is a kind of an admin of the whole system.
//it contains all the registered entities.

class System
{
	vector <Member*> allMembersArr;
	vector <FanPage*> allFanPagesArr;

public :
	System();
	System(const System& other) = delete;
	System(const System&& other) = delete;
	void addMember(const Date& birthDate, const string& name) throw(MemberException);
	void addFanPage(const string& name)throw (FanPageException);
	void addStatus(const string& name, const string& statusToAdd, int statusType) noexcept (false);
	void addStatusToFanPage(const string& name, const string& statusToAdd, int statusType)noexcept (false);
	void addMemberToFanPage(const string& fanPageName, const string& memberToAdd)noexcept(false);
	Status* getStatus(int statusType, const string& statusToAdd)throw(StatusTypeException);
	int isMemberAlreadyExist(const string& name)  const;
	int isMemberAlreadyExistWithExc(const string& name) const throw(MemberNotExistException);
	int isFanPageAlreadyExist(const string& name) const;
	int isFanPageAlreadyExistWithExc(const string& name) const throw(FanPageNotExistException);

	void showStatusesOfMember(const string& name) const noexcept (false);
	void showStatusesOfFanPage(const string& name)const noexcept (false);
	void showLast10Statuses(const string& name) const noexcept(false);
	void showMembers() const;
	void showFanPages()  const;
	void showAllFriendsOfMember(const string& name)const noexcept (false);
	void showAllFollowersOfFanPage(const string& name) const noexcept (false);
	void friendShipLinkBetweenTwoMembers(const string& name, const string& nameOfmemberToAdd) noexcept (false);
	void deleteFriendShipBetweenTwoMembers(const string& nameOfFirstMember, const string& nameOfMemberToRemove)noexcept(false);
	void deleteMemberFromFanPage(const string& fanPageName, const string& nameOfMemberToRemove) throw(FanPageFollowException);
	void createFile() const;
	void initSystem();
	~System();
};



#endif // !__SYSTEM_H



