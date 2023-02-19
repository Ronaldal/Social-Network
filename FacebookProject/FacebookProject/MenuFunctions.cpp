#include "MenuFunctions.h"
#include "System.h"

void printMenu()
{
	cout << "\n--------MENU--------\nPlease pick your option:" << endl;
	cout << "1- Add a friend" << endl;
	cout << "2- Add fan page" << endl;
	cout << "3- Add a status to a friend / fan page." << endl;
	cout << "4- View all statuses of a member / fan page." << endl;
	cout << "5- View the 10 most recent statuses of his friends." << endl;
	cout << "6- A friendship link between two friends." << endl;
	cout << "7- Unfriending between two friends " << endl;
	cout << "8- Add a member to fan page " << endl;
	cout << "9- Remove a member from the fan page" << endl;
	cout << "10- Show all entities registered to the system" << endl;
	cout << "11- Show all the friends of a certain friend / the fans of a certain fan page" << endl;
	cout << "12- Exit." << endl;
}
//the main function that runs the system, using switch case for every member or fan page choose.
void Running(int memberChoose, System& system)
{
	try {
		if (memberChoose != EXIT && memberChoose != SHOW_ALL_ENTITIES)
		{
			string name;
			getName(name);
			switch (memberChoose)
			{
			case ADD_MEMBER:
				addMemberToSystem(system, name);
				break;
			case ADD_FAN_PAGE:
				addFanPageToSystem(system, name);
				break;
			case ADD_STATUS:
				addStatusToMemberOrFanPage(system, name);
				break;
			case SHOW_STATUSES:
				viewAllStatusesOfMemberOrFanPage(system, name);
				break;
			case SHOW_10_STATUSES:
				viewLast10Statuses(system, name);
				break;
			case LINK_FRIENDS:
				friendShipLinkBetweenTwoMembers(system, name);
				break;
			case DELETE_FRIENSHIP:
				unfriendingBetweenTwoMembers(system, name);
				break;
			case ADD_MEMBER_TO_FAN_PAGE:
				addMemberToFanPage(system, name);
				break;
			case DELETE_MEMBER_FROM_FAN_PAGE:
				deleteMemberFromFanPage(system, name);
				break;
			case SHOW_ALL_FRIENDS_OR_FOLLOWERS:
				showAllFriendsOfMemberOrFanPage(system, name);
				break;
			}
		}
		else
		{
			if (memberChoose == SHOW_ALL_ENTITIES)
				showAllEntitiesRegisteredToSystem(system);
			else
			{ 
				cout << "Goodbye." << endl;
				system.createFile();
			}

		}
	}
	catch (const char* msg) { cout << msg << endl; }
}

void getName(string& name) noexcept (false)
{
	cout << "Please enter your name:" << endl;
	cleanBuffer();
	getline(cin, name);
	if (name == "\n" || name.size() == 0 || name[0]==' ')
	{
		throw "Invalid name!";
	}
}
//adding member to system
void addMemberToSystem(System& system, const string& name)
{
	try {
		cout << "Please enter your date of birth(day  month  year)" << endl;
		int day, month, year;
		cin >> day >> month >> year;
		Date d(day, month, year);

		system.addMember(d, name);
		cout << "The member added successfully" << endl;
	}//relevant exceptions the try block may cause. 
	catch (MemberException& e) { cout << e.what() << endl; }
	catch (DateException& e) { cout << e.what() << endl; }
	catch (...) { cout << "Unknown Error\n"; }

}

void addFanPageToSystem(System& system, const string& name)
{
	try {
		system.addFanPage(name);
		cout << "The fan page added successfully" << endl;
	}
	catch (FanPageException& e) { cout << e.what() << endl; }
}
void getUserType(char& choose, System& system, const string& name)throw(UserTypeException)
{
	cout << "Please Pick your type (M=member or F=fan page): " << endl;
	cin >> choose;
	if (choose != 'M' && choose != 'F')
		throw UserTypeException();
}
void addStatusToMemberOrFanPage(System& system, const string& name)
{
	try
	{
		char choose;
		int statusType;
		getUserType(choose, system, name);
		string statusToAdd;
		cout << "Please choose status type: \n1 for Text\n2 for Video\n3 for Picture" << endl;
		cin >> statusType;
		cout << "Please enter status : " << endl;
		cleanBuffer();
		getline(cin, statusToAdd);

		if (choose == 'M')
			system.addStatus(name, statusToAdd, statusType);
		else
			system.addStatusToFanPage(name, statusToAdd, statusType);

		cout << "The status added succesfully" << endl;
	
	}
	catch (UserTypeException& e ){ cout << e.what() << endl;}
	catch (MemberNotExistException& e ){ cout << e.what() << endl;}
	catch (FanPageNotExistException& e ){ cout << e.what() << endl;}
}

void viewAllStatusesOfMemberOrFanPage(System& system, const string& name)
{
	try {
		char choose;
		getUserType(choose, system, name);
		if (choose == MEMBER)
			system.showStatusesOfMember(name);
		else
			system.showStatusesOfFanPage(name);
	}
	catch (UserTypeException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
	catch (FanPageNotExistException& e) { cout << e.what() << endl; }
}
void viewLast10Statuses(System& system, const string& name)
{
	try {
		system.showLast10Statuses(name);
	}
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
}


void friendShipLinkBetweenTwoMembers(System& system, const string& name)
{
	try {
		string nameOfMemberToAdd;
		cout << "Please enter the name of the member you want to add as a friend" << endl;
		getline(cin, nameOfMemberToAdd);
		system.friendShipLinkBetweenTwoMembers(name, nameOfMemberToAdd);
		cout << "The friend succesfully added" << endl;
	}
	catch (AddMemberException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
}
void unfriendingBetweenTwoMembers(System& system, const string& name)
{
	string nameOfMemberToRemove;
	cout << "Please enter the name of the member you want to remove from your friends" << endl;
	getline(cin, nameOfMemberToRemove);
	try {
		system.deleteFriendShipBetweenTwoMembers(name, nameOfMemberToRemove);
		cout << "The friend succesfully removed" << endl;
	}
	catch (RemoveMemberException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
}
//add member to fan page.
void addMemberToFanPage(System& system, const string& nameOfFanPage)
{
	string nameOfMemberToAdd;
	cout << "Please enter the name of the member you want to add" << endl;
	getline(cin, nameOfMemberToAdd);
	try {
		system.addMemberToFanPage(nameOfFanPage, nameOfMemberToAdd);
		cout << "The member succesfully added" << endl;
	}
	catch (AddMemberException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
	catch (FanPageNotExistException& e) { cout << e.what() << endl; }
}
void deleteMemberFromFanPage(System& system, const string& nameOfFanPage)
{
	string nameOfMemberToRemove;
	cout << "Please enter the name of the member you want to delete" << endl;
	getline(cin, nameOfMemberToRemove);
	try {
		system.deleteMemberFromFanPage(nameOfFanPage, nameOfMemberToRemove);
		cout << "The member removed succesfully" << endl;
	}
	catch (FanPageFollowException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
	catch (FanPageNotExistException& e) { cout << e.what() << endl; }
}
void showAllEntitiesRegisteredToSystem(System& system)
{
	cout << "The members that are registered to the system are:" << endl;
	system.showMembers();
	cout << "The fan pages that are registered to the system are:" << endl;
	system.showFanPages();
}
void showAllFriendsOfMemberOrFanPage(System& system, const string& name)
{
	char choose;
	try {
		getUserType(choose, system, name);
		if (choose == MEMBER)
			system.showAllFriendsOfMember(name);
		else
			system.showAllFollowersOfFanPage(name);
	}
	catch (UserTypeException& e) { cout << e.what() << endl; }
	catch (MemberNotExistException& e) { cout << e.what() << endl; }
	catch (FanPageNotExistException& e) { cout << e.what() << endl; }
}
void getChoose(int& choose)throw (UserChooseException)
{
	cin >> choose;
	if (choose < 1 || choose > 12)
		throw UserChooseException();
}

//for cin.getline
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}