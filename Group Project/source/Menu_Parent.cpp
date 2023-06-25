#include "../header/Menu_Parent.h"

using namespace std;

int MenuParent::execute()
{
	utils.clear();
	int selection;
	do
	{
		cout << "\nWelcome " << db.currentUser.getName() << " to Parent Homescreen\n\n";

		cout << "1) View Child's Record\n";
		cout << "2) School Notices\n";
		cout << "3) Exit\n";

		cout << "Enter selection: ";

		selection = getInput.getNumber();

		if (selection == 1)
			this->childRecord();

		else if (selection == 2)
			this->schoolNotice();

		else
			cout << "\nInvalid choice!\n";

	} while (selection != 3);
	cout << "\nGoodbye!";

	return 0;
}

void MenuParent::childRecord()
{
	utils.clear();
	string childName;
	optional<Student> student;
	int childClassroomNumber;
	cout << "View Child's Record\n\n";
	cout << "Enter your kid's Name and Class:\n\n";
	// TODO Take user's input to check with current data
	cout << "Student's Name: ";
	childName = getInput.getString();
	cout << "\nStudent's Class: ";
	childClassroomNumber = getInput.getNumber();
	// TODO Add if statement to check if that student exists
	//if(studentName )

	bool classroomNumberExists = false;
	bool childExists = false;

	for (int i = 0; i < db.db.size(); i++)
	{

		if (db.db[i].type != UserType::Teacher)
			continue;

		if (db.db[i].teacher->classRoom.classRoomNumber != childClassroomNumber)
			continue;

		for (int j = 0; j < db.db[i].teacher->classRoom.students.size(); j++)
		{
			if (db.db[i].teacher->classRoom.students[j].name == childName)
			{
				childExists = true;
				student = db.db[i].teacher->classRoom.students[j];
				break;
			}
		}
	}
	// TODO Else if student does exsist
	cout << "\n\nThis is the Record for 'students name'"<< "\n";
	cout << "Full Name: " << student->name << "\n";
	cout << "\nGender: " << (student->gender ? "Male":"Female") << "\n";
	cout << "\nMaths: " << student->math << "\n";
	cout << "\nScience: " << student->science << "\n";
	cout << "\nWriting: " << student->writing << "\n";
	cout << "\nReading: " << student->writing << "\n";
	cout << "\nOthers: " << student->other << "\n";
	cout << "\nLearning Progress: " << student->learningProgress << "\n";
	cout << "\n";

	utils.waitForKeyPress();
	utils.clear();
}
void MenuParent::schoolNotice()
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