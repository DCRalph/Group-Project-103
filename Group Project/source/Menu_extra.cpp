#include "../header/Menu_extra.h"

int MenuExtra::execute(int choice)
{
	cout << choice;
	if (choice == 3)
	{
		this->displayContact();
	}
	else if (choice == 4)
	{
		this->displayEvent();
	}
	else
	{
		cout << "Invalid choice" << endl;
	}
	utils.waitForKeyPress();
	return 0;
}

void MenuExtra::displayContact()
{
	utils.clear();
	cout << ("School Contact Details:") << endl
			 << endl;
	cout << ("Email : contact.us@yoobeecollege.co.nz") << endl;
	cout << ("Phone Number : 021 837 0394") << endl;
	utils.waitForKeyPress();
}

void MenuExtra::displayEvent()
{
	utils.clear();

	cout << ("Upcoming Events:") << endl
			 << endl;
	cout << ("21st June : Boys football on top feild 9am - 11am") << endl;
	cout << ("25th June : School band preformace at lunch time in hall") << endl;
	cout << ("28th June : School Closed for parent teacher interviews 9am - 2pm") << endl;
	utils.waitForKeyPress();
}