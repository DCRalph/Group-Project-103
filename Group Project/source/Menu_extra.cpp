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
	cout << "		---------------------------\n";
	cout << "		| School Contact Details: |\n";
	cout << "		---------------------------";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "	   Email : contact.us@yoobeecollege.co.nz";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "		Phone Number : 021 837 0394";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	utils.waitForKeyPress();
}

void MenuExtra::displayEvent()
{
	utils.clear();
	cout << "			--------------------\n";
	cout << "			| Upcoming Events: |\n";
	cout << "			--------------------";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "21st June : Boys football on top feild 9am - 11am";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "25th June : School band preformace at lunch time in hall";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "28th June : School Closed for parent teacher interviews 9am - 2pm";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	utils.waitForKeyPress();
}