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

		cout << C.cyan("1.") << " Student Records\n";
		cout << C.red("2.") << " Exit\n";
		cout << "Enter selection: ";
		selection = getInput.getNumber();

		if (selection == 1)
		{
			StudentRecord.execute();
		}
		else
		{
			cout << "\nInvalid choice!\n";
		}
	} while (selection != 2);
	// cout << "\nGoodbye!";

	return 0;
}