#include "MenuFunctions.h"
using namespace std;

int main()
{
	System s;
	s.initSystem();
	int choose;

	do {
		printMenu();
		try {
			getChoose(choose);
			Running(choose, s);
		}
		catch (UserChooseException& e) { cout << e.what() << endl; }
		catch (...) { cout << "Unknown Error\n"; }
	} while (choose != EXIT);
}
