#include "../header/Menu_Extra.h"

void MenuExtra::execute()
{
	utils.clear();
	utils.waitForKeyPress();
	return;
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