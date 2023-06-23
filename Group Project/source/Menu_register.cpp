#include "../header/Menu_Register.h"

int MenuRegister::execute()
{
	int userOccupation;
	cout << ("Occupation") << endl
			 << "1)Teacher\n2)Parent: ";
	cin >> userOccupation;
	switch (userOccupation)
	{
	case 1:
		cout << "Teacher Registration" << endl
				 << endl;
		cout << endl
				 << "Full Name: ";

		cout << endl
				 << "Gender: ";

		cout << endl
				 << "Date of Birth: ";

		cout << endl
				 << "Email: ";

		cout << endl
				 << "Contact Number: ";

		cout << endl
				 << "Classroom Number: ";

		cout << endl
				 << "Teaching Year(eg: year 1): ";

		cout << endl
				 << "Username: ";

		cout << endl
				 << "Password: ";

		cout << endl;
		utils.waitForKeyPress();
		utils.clear();
		break;
	case 2:
		cout << "Parent Registration" << endl
				 << endl;
		cout << endl
				 << "Full Name: ";

		cout << endl
				 << "Gender: ";

		cout << endl
				 << "Date of Birth: ";

		cout << endl
				 << "Email: ";

		cout << endl
				 << "Contact Number: ";

		cout << endl
				 << "Child Full Name(s): ";

		cout << endl
				 << "Child(s) Classroom Number: ";

		cout << endl
				 << "Parent/Caregiver Emergency Contact Number: ";

		cout << endl
				 << "Username: ";

		cout << endl
				 << "Password: ";

		cout << endl;
		utils.waitForKeyPress();
		utils.clear();
		break;
	}

	return 0;
}