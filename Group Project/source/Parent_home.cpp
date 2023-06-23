#include "../header/Parent_home.h"

int ParentMenu::execute()
{
	utils.clear();
	string name;
	cout << "What's your name?\n\n";
	name = getInput.getString();
	name[0] = toupper(name[0]);
	int selection;
	do
	{
		cout << "\nWelcome " << name << " to Parent Homescreen\n\n";
		cout << "1) View Child's Record\n";
		cout << "2) School Notices\n";
		;
		cout << "3) Exit\n";
		cout << "Enter selection: ";
		selection = getInput.getNumber();
		if (selection == 1)
		{
			this->childRecord();
		}
		else if (selection == 2)
		{
			this->schoolNotice();
		}
		else if (selection == 3)
		{
			cout << "\nGoodbye!\n";
			return (0);
		}
		else
		{
			cout << "\nInvalid choice!\n";
		}
	} while (selection != 2);
	cout << "\nGoodbye!";

	return 0;
}

void ParentMenu::childRecord()
{
	utils.clear();
	cout << "View Child's Record\n\n";
	cout << "Enter your kid's Name and Class:\n\n";
	// TODO Take user's input to check with current data
	cout << "Student's Name: ";

	cout << "\nStudent's Class: ";

	// TODO Add if statement to check if that student exists

	// TODO Else if student does exsist
	cout << "\n\nThis is the Record for 'students name'";
	cout << "\nFull Name: ";
	cout << "\nGender: ";
	cout << "\nMaths: ";
	cout << "\nScience: ";
	cout << "\nWriting: ";
	cout << "\nReading: ";
	cout << "\nOthers: ";
	cout << "\nLearning Progress: ";
	cout << "\n";
	utils.waitForKeyPress();
	utils.clear();
}
void ParentMenu::schoolNotice()
{
	utils.clear();
	cout << "School Notices\n\n";
	cout << "7th July 2023\n\nAll the students will be pleased to know that our school is organising a five-day tour to The Nelson Provincial Museum\n		Classes - 3 to 5\n"
		 << "	Date of departure - 22nd July 2023\n	Date of return - 27 July 2023\n"
		 << "Those who are interested may deposit $500/ - per head. The cost is inclusive of sight seeing, boarding and loding at a 3-star hotel.\nPlease do so by 12th July"
		 << "\n-Chris";
	cout << "\n\n13th July 2023\n\nChildren are informed that our school is having a sale of its old sports equipment like cricket bats, badmintion rackets, footballs, cricket and football equipment etc. in the P.E. Room. Those interesed in purchasing the sports products can ettend the P.E. Room on the announced date during school hours or recess time.";
	cout << "\n-Sarita\nHead of Department\n\n";
	utils.waitForKeyPress();
	utils.clear();
}