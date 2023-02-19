#include "System.h"

void cleanBuffer();
void printMenu();
void Running(int memberChoose, System& system);
void getName(string& name) noexcept (false);
void addFanPageToSystem(System& system, const string& name);
void addMemberToSystem(System& system, const string& name);
void addStatusToMemberOrFanPage(System & system, const string& name);
void viewAllStatusesOfMemberOrFanPage(System& system, const string& name);
void viewLast10Statuses(System& system, const string& name);
void friendShipLinkBetweenTwoMembers(System& system, const string& name);
void unfriendingBetweenTwoMembers(System& system, const string& name);
void addMemberToFanPage(System& system, const string& nameOfFanPage);
void deleteMemberFromFanPage(System& system, const string& name);
void showAllEntitiesRegisteredToSystem(System& system);
void showAllFriendsOfMemberOrFanPage(System& system, const string& name);
void getChoose(int& choose)throw (UserChooseException);
void getUserType(char& choose, System& system, const string& name)throw(UserTypeException);
