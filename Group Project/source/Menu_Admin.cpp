#include "../header/Menu_Admin.h"

using namespace std;

int MenuAdmin::execute()
{
	int selection;
	do
	{
		utils.clear();

		cout << "\nWelcome " << db.currentUser.getName() << " to Admin Homescreen\n\n";
		cout << "1. Parent Records\n";
		cout << "2. Class Records\n";
		cout << "3. Student Report\n";
		cout << "4. Exit\n";
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
			cout << ("Invalid input, please try again.") << "\n\n";

			utils.waitForKeyPress();
		}
	} while (selection != 4);

	return 0;
}

void MenuAdmin::parentRecords()
{
	utils.clear();
	string parentName;
	optional<class::Parent> parent;

	cout << "Parent Records\n\n";
	// TODO Take user's input to check with current data
	cout << "Enter the Parent's Name:\n";
	parentName = getInput.getString();

	// TODO Add statement to check if that parent exists
	bool parentExists = false;

	for (int i = 0; i < db.db.size(); i++)
	{

		if (db.db[i].type != UserType::Parent)
			continue;
		if (db.db[i].parent->name == parentName)
		{

			parentExists = true;
			parent = db.db[i].parent;
			break;
		}
	}

	// TODO Else if parent does exsist
	cout << "\nThis is 'Parents Name' Record:\n\n";
	cout << "Full Name: " << parent->name << "\n";
	cout << "Gender: " << (parent->gender ? "Male" : "Female") << "\n";
	cout << "Date of Birth: " << parent->dob << "\n";
	cout << "Email: " << parent->email << "\n";
	cout << "Contact Number: " << parent->contactNumber << "\n";
	cout << "Child(s) Full Name: " <<0 << "\n"; //
	cout << "Child(s) Classroom Number: " << 0 << "\n"; //
	cout << "Parent/Caregiver Emergency Contact Number: " << 0 << "\n"; // 

	utils.waitForKeyPress();
}

void MenuAdmin::classRecords()
{
	for (User u : db.db)
	{
		if (u.teacher.has_value())
		{
			for (Student s : u.teacher->classRoom.students)
			{
				cout << "Name: " << s.name << "\n";
				cout << "Gender: " << s.gender << "\n";
				cout << "Date of Birth: " << s.dob << "\n";
				cout << "Maths: " << s.math << "\n";
				cout << "Science: " << s.science << "\n";
				cout << "Writing: " << s.writing << "\n";
				cout << "Reading: " << s.reading << "\n";
				cout << "Others: " << s.other << "\n";
				cout << "Learning Progress: " << s.learningProgress << "\n";
			}
		}
	}
	//utils.clear();

	//optional<Student> student;
	//int childClassroomNumber;

	//cout << "Class Records\n\n";
	//// TODO Take user's input to check with current data
	//cout << "What Class do you want to view?:\n\n";
	//childClassroomNumber = getInput.getNumber();
	//// TODO Add if statement to check if class exists
	//bool classroomNumberExists = false;

	//for (int i = 0; i < db.db.size(); i++)
	//{
	//	if (db.db[i].teacher->classRoom.classRoomNumber != childClassroomNumber)
	//		continue;

	//	for (int j = 0; j < db.db[i].teacher->classRoom.students.size(); j++)
	//	{
	//		/*if (db.db[i].classRoomNumber == childClassroomNumber)
	//		{
	//			student = db.db[i].teacher->classRoom.students[j];
	//			break;
	//		}*/
	//	}
	//}

	//// TODO Else if class does exsist
	//// TODO While loop to display all students in that class
	//cout << "\nRoom 12's Records:\n\n";
	//cout << "1) William Brown: \n";
	//cout << "	(William's Student Details)\n";
	//cout << "2) Steve Gine: \n";
	//cout << "	(Steve Gine Student Details)\n";
	//cout << "3) Alex Humbin: \n";
	//cout << "	(Alex Humbin Student Details)\n";
	//cout << "...\n";

	//utils.waitForKeyPress();
}

void MenuAdmin::studentReport()
{
	utils.clear();

	optional<Student> student;

	cout << "Student Report\n\n";
	cout << "What Group do you want to view?\n";
	cout << "1) Needs Help\n2) Progressing State\n\n";
	int selection = getInput.getNumber();
	cout << "\nStudents who need help:\n\n";
	for (int i = 0; db.db.size();) 
	{
		for (int i = 0; i < db.db.size(); i++)
		{

			if (db.db[i].type != UserType::Teacher)
				continue;
		
			if (selection == 1)
			{
				/*for (int j = 0; db.db[i].teacher->classRoom();)
				{
					if (db.db[i].teacher->classRoom.students->learningProgress[j] == "Need Help") {
						// TODO Add the real details of the students
						cout << j << ") " << student->name << "\n";
					}
				}*/
			}
			else if (selection == 2)
			{
				// TODO Add the real details of the students
				cout << "\nStudents who are progressing:\n\n";
				cout << "1) Bill Hans: \n";
				cout << "2) Chris Ball: \n";
				cout << "3) Lizzy Stemp: \n";
			}	cout << "...\n";
		}
	}
	utils.waitForKeyPress();
}