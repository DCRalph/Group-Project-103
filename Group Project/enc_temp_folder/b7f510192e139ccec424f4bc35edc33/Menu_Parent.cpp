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

	string learningProgress;
	
	switch (student->learningProgress)
	{
	case LearningProgress::Achieved:
		learningProgress = "Achieved";
		break;
	case LearningProgress::Need_Help:
		learningProgress = "Needs Help";
		break;
	case LearningProgress::Progressing:
		learningProgress = "Progressing";
		break;
	case LearningProgress::Not_Applicable:
		learningProgress = "Not Applicable";
		break;
	}

	cout << "\n\nThis is the Record for 'students name'"<< "\n";
	cout << "Full Name: " << student->name << "\n";
	cout << "\nGender: " << (student->gender ? "Female":"Male") << "\n";
	cout << "\nMaths: " << student->math << "% / 100%\n";
	cout << "\nScience: " << student->science << "% / 100%\n";
	cout << "\nWriting: " << student->writing << "% / 100%\n";
	cout << "\nReading: " << student->writing << "% / 100%\n";
	cout << "\nOthers: " << student->other << "% / 100%\n";
	cout << "\nLearning Progress: " << learningProgress << "\n";
	cout << "\n";

	utils.waitForKeyPress();
	utils.clear();
}
void MenuParent::schoolNotice()
{
	utils.clear();
	cout << "		-------------------\n";
	cout << "		| School Notices: |\n";
	cout << "		-------------------";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "7th July 2023\n\n" << 
		"All the students will be pleased to know that our school is organising a five-day tour to The Nelson Provincial Museum\n" <<	
		"		Classes - 3 to 5\n"
			 << "	Date of departure - 22nd July 2023\n	Date of return - 27 July 2023\n"
			 << "Those who are interested may deposit $500/ - per head." 
		<< "\nThe cost is inclusive of sight seeing, boarding and loding at a 3-star hotel." 
		<< "\nPlease do so by 12th July"
		<< "\n-Chris";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "13th July 2023\n\nChildren are informed that our school is having a sale of its old sports equipment like cricket bats, badmintion rackets, footballs, cricket and football equipment etc. in the P.E. Room. Those interesed in purchasing the sports products can ettend the P.E. Room on the announced date during school hours or recess time.";
	cout << "\n-Sarita\nHead of Department\n\n";
	utils.waitForKeyPress();
	utils.clear();
}