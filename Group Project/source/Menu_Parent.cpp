#include "../header/Menu_Parent.h"

using namespace std;

int MenuParent::execute()
{
	utils.clear();
	int selection;
	do
	{
		utils.clear();
		cout << "\nWelcome " << db.currentUser.getName() << " to Parent Homescreen\n\n";

		cout << C.red("0.") << " Exit\n";
		cout << C.cyan("1.") << " View Child's Record\n";
		cout << C.cyan("2.") << " School Notices\n";

		cout << "Enter selection: ";

		selection = getInput.getNumber();

		switch (selection)
		{
		case 0:
			break;
		case 1:
			this->childRecord();
			break;
		case 2:
			this->schoolNotice();
			break;

		default:
			utils.clear();
			cout << "\n";
			cout << C.red("Invalid input, please try again.") << "\n\n";

			utils.waitForKeyPress();
		}

	} while (selection != 0);
	// cout << "\nGoodbye!";

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

	cout << "Student's Name: ";
	childName = getInput.getString();
	cout << "\nStudent's Class: ";
	childClassroomNumber = getInput.getNumber();

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

	if (!childExists)
	{
		cout << "\n\n"
				 << C.red("Child does not exist!")
				 << "\n\n";
		utils.waitForKeyPress();
		return;
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
	utils.clear();
	cout << "This is the Record for '" << student->name << "'";
	cout << "\n\n----------------------------------------------\n\n";
	cout << "Name: " << student->name << "\n";
	cout << "\nGender: " << (student->gender ? "Female" : "Male") << "\n";
	cout << "\nMaths: " << student->math << "% / 100%\n";
	cout << "\nScience: " << student->science << "% / 100%\n";
	cout << "\nWriting: " << student->writing << "% / 100%\n";
	cout << "\nReading: " << student->writing << "% / 100%\n";
	cout << "\nOthers: " << student->other << "% / 100%\n";
	cout << "\nLearning Progress: " << learningProgress << "\n";
	cout << "\n";

	utils.waitForKeyPress();
}
void MenuParent::schoolNotice()
{
	utils.clear();
	cout << "		-------------------\n";
	cout << "		| School Notices: |\n";
	cout << "		-------------------";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "- 7th July 2023\n\n"
			 << "All the students will be pleased to know that our school is organising a five-day tour to The Nelson Provincial Museum\n"
			 << "		Classes - 3 to 5\n"
			 << "	Date of departure - 22nd July 2023\n	Date of return - 27 July 2023\n"
			 << "Those who are interested may deposit $500/ - per head."
			 << "\nThe cost is inclusive of sight seeing, boarding and loding at a 3-star hotel."
			 << "\nPlease do so by 12th July"
			 << "\n- Chris";
	cout << "\n\n--------------------------------------------------------------------\n\n";
	cout << "- 13th July 2023\n\nChildren are informed that our school is having a sale of its old sports equipment like cricket bats, badmintion rackets, footballs, cricket and football equipment etc. in the P.E. Room. Those interesed in purchasing the sports products can ettend the P.E. Room on the announced date during school hours or recess time.";
	cout << "\n- Sarita\nHead of Department\n\n";
	utils.waitForKeyPress();
}