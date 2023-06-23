#include "../header/Menu_Teacher.h"

int MenuTeacher::execute()
{
	StudentRecord StudentRecord;

	utils.clear();

	int selection;
	do
	{
		cout << "Welcome " << db.currentUser.getName() << " to Teacher Homescreen\n\n";
		cout << "1) Student Records\n";
		cout << "2) Exit\n";
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
	cout << "\nGoodbye!";

	return 0;
}