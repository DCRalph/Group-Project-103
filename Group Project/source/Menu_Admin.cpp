#include "../header/Menu_Admin.h"

using namespace std;

int MenuAdmin::execute()
{
	int selection;
	do
	{
		utils.clear();

		cout << "\nWelcome " << db.currentUser.getName() << " to Admin Homescreen\n\n";
		cout << "1) Parent Records\n";
		cout << "2) Class Records\n";
		cout << "3) Student Report\n";
		cout << "4) Exit\n";
		cout << "Enter selection: ";

		selection = getInput.getNumber();

		switch (selection)
		{
		case 1:
			this->parentRecords();
			break;
		case 2:
			this->classRecords();
			break;
		case 3:
			this->studentReport();
			break;
		case 4:
			cout << "\nGoodbye!";
			break;
		default:
			utils.clear();
			cout << "\n";
			cout << C.red("Invalid input, please try again.") << "\n\n";

			utils.waitForKeyPress();
		}
	} while (selection != 4);

	return 0;
}

void MenuAdmin::parentRecords()
{
	utils.clear();
	cout << "Parent Records\n\n";
	// TODO Take user's input to check with current data
	cout << "Enter the Parent's Name:\n";

	// TODO Add if statement to check if that parent exists

	// TODO Else if parent does exsist
	cout << "\nThis is 'Parents Name' Record:\n\n";
	cout << "Full Name: \n";
	cout << "Gender: \n";
	cout << "Date of Birth: \n";
	cout << "Email: \n";
	cout << "Contact Number: \n";
	cout << "Child(s) Full Name: \n";
	cout << "Child(s) Classroom Number: \n";
	cout << "Parent/Caregiver Emergency Contact Number: \n";

	utils.waitForKeyPress();
}

void MenuAdmin::classRecords()
{
	utils.clear();
	cout << "Class Records\n\n";
	// TODO Take user's input to check with current data
	cout << "What Class do you want to view?:\n\n";

	// TODO Add if statement to check if class exists

	// TODO Else if class does exsist
	// TODO While loop to display all students in that class
	cout << "\nRoom 12's Records:\n\n";
	cout << "1) William Brown: \n";
	cout << "	(William's Student Details)\n";
	cout << "2) Steve Gine: \n";
	cout << "	(Steve Gine Student Details)\n";
	cout << "3) Alex Humbin: \n";
	cout << "	(Alex Humbin Student Details)\n";
	cout << "...\n";

	utils.waitForKeyPress();
}

void MenuAdmin::studentReport()
{
	utils.clear();
	cout << "Student Report\n\n";
	cout << "What Group do you want to view?\n";
	cout << "1) Needs Help\n2) Progressing State\n\n";
	int selection = getInput.getNumber();
	if (selection == 1)
	{
		// TODO Add the real details of the students
		cout << "\nStudents who need help:\n\n";
		cout << "1) William Brown: \n";
		cout << "2) Steve Gine: \n";
		cout << "3) Alex Humbin: \n";
		cout << "...\n";
	}
	else if (selection == 2)
	{
		// TODO Add the real details of the students
		cout << "\nStudents who are progressing:\n\n";
		cout << "1) Bill Hans: \n";
		cout << "2) Chris Ball: \n";
		cout << "3) Lizzy Stemp: \n";
		cout << "...\n";
	}
	else
	{
		cout << "\nInvalid choice!\n";
	}
	utils.waitForKeyPress();
}