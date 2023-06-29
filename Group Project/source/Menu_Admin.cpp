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
	cout << "Enter the Parent's Name:\n";
	parentName = getInput.getString();

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

	if (!parentExists)
	{
		cout << "Parent not found.\n";
		utils.waitForKeyPress();
		return;
	}

	string childsClassRoom;
	string childsName;
	bool childExists = false;

	for (int i = 0; i < db.db.size(); i++)
	{
		if (db.db[i].type != UserType::Teacher)
			continue;

		for (int j = 0; j < db.db[i].teacher->classRoom.students.size(); j++)
		{
			for (const string& childId : parent->childIds)
			{
				if (db.db[i].teacher->classRoom.students[j].id == childId)
				{
					childExists = true;
					childsName = db.db[i].teacher->classRoom.students[j].name;
					childsClassRoom = to_string(db.db[i].teacher->classRoom.classRoomNumber);
					break;
				}
			}
			if (childExists)
				break;
		}
		if (childExists)
			break;
	}
	utils.clear();
	cout << "This is '" << parent->name << "s' Record:\n\n";
	cout << "Name: " << parent->name << "\n";
	cout << "Gender: " << (parent->gender == Gender::Male ? "Male" : "Female") << "\n";
	cout << "Date of Birth: " << parent->dob << "\n";
	cout << "Email: " << parent->email << "\n";
	cout << "Contact Number: " << parent->contactNumber << "\n";
	cout << "Child(s) Name: " << childsName << "\n";
	cout << "Child(s) Classroom Number: " << childsClassRoom << "\n";
	if (int i = 1 < parent->childIds.size()) {
		while (i != parent->childIds.size()) {
			cout << "Child(s) Name: " << childsName << "\n";
			cout << "Child(s) Classroom Number: " << childsClassRoom << "\n";
			i++;
		}
	}
	cout << "Parent/Caregiver Emergency Contact Number: " << parent->emergencyContactNumber << "\n";

	utils.waitForKeyPress();
}

void MenuAdmin::classRecords()
{
	utils.clear();
	string edu[] = { "Achieved", "Progressing", "Needs Help", "NA" };
	int classroom;
	cout << "Enter the class number: ";
	classroom = getInput.getNumber();
	utils.clear();
	cout << "Class Room " << classroom << "'s Student Records:";
	for (User u : db.db)
	{
		if (u.teacher.has_value())
		{
			if (classroom == u.teacher->classRoom.classRoomNumber)
			{
				for (Student s : u.teacher->classRoom.students)
				{
					cout << "\n\n----------------------------------------------\n\n";
					cout << "Name: " << s.name << "\n";
					cout << "Gender: " << (s.gender == Gender::Male ? "Male" : "Female") << "\n";
					cout << "Date of Birth: " << s.dob << "\n";
					cout << "Maths: " << s.math << "\n";
					cout << "Science: " << s.science << "\n";
					cout << "Writing: " << s.writing << "\n";
					cout << "Reading: " << s.reading << "\n";
					cout << "Others: " << s.other << "\n";
					cout << "Learning Progress: " << edu[s.learningProgress] << "\n";
				}
			}
		}
	}
	utils.waitForKeyPress();
}

void MenuAdmin::studentReport()
{
	utils.clear();
	cout << "Student Report\n\n";
	cout << "What Group do you want to view?\n";
	cout << "1) Needs Help\n2) Progressing State\n\n";
	int selection = getInput.getNumber();
	utils.clear();
	if (selection == 1)
		cout << "Students who need help:\n";
	if (selection == 2)
		cout << "Students who are progressing:\n";

	for (const User& user : db.db)
	{
		if (user.type != UserType::Teacher)
			continue;

		const class::Teacher& teacher = user.teacher.value();
		const ClassRoom& classRoom = teacher.classRoom;

		if (selection == 1)
		{
			for (const Student& student : classRoom.students)
			{
				if (student.learningProgress == LearningProgress::Need_Help)
					cout << "- " << student.name << "\n";
			}
		}
		else if (selection == 2)
		{
			for (const Student& student : classRoom.students)
			{
				if (student.learningProgress == LearningProgress::Progressing)
					cout << "- " << student.name << "\n";
			}
		}
	}

	utils.waitForKeyPress();
}