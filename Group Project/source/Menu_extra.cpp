#include "../header/Menu_Extra.h"

using namespace std;

// void MenuExtra::execute()
// {
// 	utils.clear();
// 	utils.waitForKeyPress();
// 	return;
// }

void MenuExtra::displayContact()
{
	utils.clear();
	cout << ("School Contact Details:") << "\n"
			 << "\n";
	cout << ("Email : contact.us@yoobeecollege.co.nz") << "\n";
	cout << ("Phone Number : 021 837 0394") << "\n";
	utils.waitForKeyPress();
}

void MenuExtra::displayEvent()
{
	utils.clear();

	cout << ("Upcoming Events:") << "\n"
			 << "\n";
	cout << ("21st June : Boys football on top feild 9am - 11am") << "\n";
	cout << ("25th June : School band preformace at lunch time in hall") << "\n";
	cout << ("28th June : School Closed for parent teacher interviews 9am - 2pm") << "\n";
	utils.waitForKeyPress();
}