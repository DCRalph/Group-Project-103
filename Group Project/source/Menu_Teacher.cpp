#include "../header/Menu_Teacher.h"

using namespace std;

int MenuTeacher::execute()
{
	StudentRecord StudentRecord;

	int selection;
	do
	{
		utils.clear();

		cout << "Welcome " << db.currentUser.getName() << " to Teacher Homescreen\n\n";
		// cout << "1. Student Records\n";
		// cout << "2. Exit\n";

		cout << C.red("0.") << " Exit\n";
		cout << C.cyan("1.") << " Student Records\n";
		cout << "Enter selection: ";
		selection = getInput.getNumber();

		switch (selection)
		{
		case 0:
			break;
		case 1:
			StudentRecord.execute();
			break;
		default:
			utils.clear();
			cout << "\n";
			cout << C.red("Invalid input, please try again.") << "\n\n";

			utils.waitForKeyPress();
		}
	} while (selection != 0);
	// cout << "\nGoodbye!";

	return 0;
}