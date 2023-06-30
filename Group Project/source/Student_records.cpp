#include "../header/Student_Records.h"

using namespace std;

int StudentRecord::execute()
{
	utils.clear();
	int opt;
	cout << "Student Records\n\n";
	cout << "1. Add Student\n";
	cout << "2. Edit student Record\n";
	cout << "3. Delete Student Record\n";
	cout << "4. Update Record\n";
	cout << "5. View the Records\n";
	cout << "Enter a number: ";
	opt = getInput.getNumber();
	if (opt == 1)
	{
		this->addStudent();
	}
	else if (opt == 2)
	{
		this->editStudent();
	}
	else if (opt == 3)
	{
		this->deleteStudent();
	}
	else if (opt == 4)
	{
		this->updateStudent();
	}
	else if (opt == 5)
	{
		this->viewStudent();
	}
	else
	{
		cout << "\nInalid Choice!\n";

		StudentRecord();
	}
	return 0;
}

void StudentRecord::addStudent()
{
	utils.clear();

	int classRoomNumber;

	string name;
	string id;
	string dob;
	string gender;
	Gender genderEnum;

	float math;
	float science;
	float english;
	float writing;
	float reading;
	float other;

	string learningProgress;
	LearningProgress learningProgressEnum;

	cout << C.brightMagenta("Add Student") << "\n\n";

	cout << "Enter the student's details: "
			 << "\n";

	cout << "Add student to your class ";
	bool myClass = getInput.getYesNo(true);

	if (myClass)
		classRoomNumber = db.currentUser.teacher->classRoom.classRoomNumber;
	else
	{
		cout << "Classroom Number: ";
		classRoomNumber = getInput.getNumber();
	}

	cout << "Name: ";
	name = getInput.getString();

	cout << "Date of Birth: ";
	dob = getInput.getString();

	bool validGender = true;
	do
	{
		cout << "\n"
				 << "Gender: ";
		gender = getInput.getString();

		for (int i = 0; i < gender.size(); i++)
			gender[i] = tolower(gender[i]);

		validGender = true;

		if (gender == "male")
			genderEnum = Gender::Male;
		else if (gender == "female")
			genderEnum = Gender::Female;
		else
			validGender = false;

		if (!validGender)
			cout << C.red("Invalid gender. Please try again.") << "\n";

	} while (!validGender);

	cout << "Maths (0% - 100%): ";
	math = getInput.getNumber();

	cout << "Science (0% - 100%): ";
	science = getInput.getNumber();

	cout << "English (0% - 100%): ";
	english = getInput.getNumber();

	cout << "Writing (0% - 100%): ";
	writing = getInput.getNumber();

	cout << "Reading (0% - 100%): ";
	reading = getInput.getNumber();

	cout << "Other (0% - 100%): ";
	other = getInput.getNumber();

	bool validLearning = true;
	do
	{
		cout << "\n"
				 << "Learning Progres: ";
		learningProgress = getInput.getString();

		for (int i = 0; i < learningProgress.size(); i++)
			learningProgress[i] = tolower(learningProgress[i]);

		validLearning = true;

		if (learningProgress == "achieved")
			learningProgressEnum = LearningProgress::Achieved;
		else if (learningProgress == "progressing")
			learningProgressEnum = LearningProgress::Progressing;
		else if (learningProgress == "need help")
			learningProgressEnum = LearningProgress::Need_Help;
		else if (learningProgress == "not applicable")
			learningProgressEnum = LearningProgress::Not_Applicable;

		else
			validLearning = false;

		if (!validLearning)
			cout << C.red("Invalid Learning Progres. Please try again.") << "\n";

	} while (!validLearning);

	id = name + " " + dob;

	Student newStudent(name, id, dob, genderEnum, math, science, english, writing, reading, other, learningProgressEnum);

	for (int i = 0; i < db.db.size(); i++)
	{
		if (db.db[i].type != UserType::Teacher)
			continue;

		if (db.db[i].teacher->classRoom.classRoomNumber == classRoomNumber)
		{
			db.db[i].teacher->classRoom.students.push_back(newStudent);
			return;
		}
	}

	cout << C.red("Classroom not found. Would you like to create one?") << "\n";
	bool createClassroom = getInput.getYesNo();

	if (!createClassroom)
	{
		cout << C.red("Student not added.") << "\n";
		return;
	}

	MenuRegister menuRegister;

	menuRegister.registerTeacher(classRoomNumber);

	db.db[db.db.size() - 1].teacher->classRoom.students.push_back(newStudent);

	cout << C.green("Student added.") << "\n";

	utils.waitForKeyPress();

	return;
}

void StudentRecord::editStudent()
{
	utils.clear();

	string childName;
	optional<Student> student;
	int childClassroomNumber;

	cout << C.brightMagenta("Edit Student") << "\n\n";
	utils.clear();

	cout << "Enter Students Name and Class:"
			 << "\n\n";

	cout << "Student's Name: ";
	childName = getInput.getString();

	cout << "Student's Class: ";
	childClassroomNumber = getInput.getNumber();

	cout << "\n";

	bool classroomNumberExists = false;
	bool childExists = false;

	int classroomIndex = -1;
	int childIndex = -1;

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
				classroomIndex = i;
				childIndex = j;
				break;
			}
		}
	}

	if (!childExists)
	{
		cout << C.red("Student does not exist!") << "\n\n";
		utils.waitForKeyPress();
		return;
	}

	int opt;

	do
	{
		utils.clear();

		cout << C.brightMagenta("What would you like to edit on ") << student->name << "\n\n";

		cout << C.cyan("0") << ". Exit"
				 << "\n";
		cout << C.cyan("1") << ". Name"
				 << "\n";
		cout << C.cyan("2") << ". Date of Birth"
				 << "\n";
		cout << C.cyan("3") << ". Gender"
				 << "\n";
		cout << C.cyan("4") << ". Maths"
				 << "\n";
		cout << C.cyan("5") << ". Science"
				 << "\n";
		cout << C.cyan("6") << ". English"
				 << "\n";
		cout << C.cyan("7") << ". Writing"
				 << "\n";
		cout << C.cyan("8") << ". Reading"
				 << "\n";
		cout << C.cyan("9") << ". Other"
				 << "\n";
		// cout << C.cyan("10") << ". Learning Progress"
		//  << "\n";

		cout << "\n";

		cout << "Enter your choice: ";
		opt = getInput.getNumber();

		switch (opt)
		{
		case 0:
		{
			cout << C.green("Exiting...") << "\n";
			return;
		}
		break;

		case 1:
		{
			cout << "Enter new name: ";
			string newName = getInput.getString();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].name = newName;
			cout << C.green("Name changed.") << "\n";
			break;
		}

		case 2:
		{
			cout << "Enter new date of birth: ";
			string newDob = getInput.getString();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].dob = newDob;
			cout << C.green("Date of birth changed.") << "\n";
			break;
		}

		case 3:
		{
			bool validGender = true;
			string gender;
			Gender genderEnum;
			do
			{
				cout << "Enter new Gender: ";
				gender = getInput.getString();

				for (int i = 0; i < gender.size(); i++)
					gender[i] = tolower(gender[i]);

				validGender = true;

				if (gender == "male")
					genderEnum = Gender::Male;
				else if (gender == "female")
					genderEnum = Gender::Female;
				else
					validGender = false;

				if (!validGender)
					cout << C.red("Invalid gender. Please try again.") << "\n";

			} while (!validGender);

			db.db[classroomIndex].teacher->classRoom.students[childIndex].dob = genderEnum;
			cout << C.green("Gender changed.") << "\n";
			break;
		}

		case 4:
		{
			cout << "Enter new maths score: ";
			int newMaths = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].math = newMaths;
			cout << C.green("Maths score changed.") << "\n";
			break;
		}

		case 5:
		{
			cout << "Enter new science score: ";
			int newScience = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].science = newScience;
			cout << C.green("Science score changed.") << "\n";
			break;
		}

		case 6:
		{
			cout << "Enter new english score: ";
			int newEnglish = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].english = newEnglish;
			cout << C.green("English score changed.") << "\n";
			break;
		}

		case 7:
		{
			cout << "Enter new writing score: ";
			int newWriting = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].writing = newWriting;
			cout << C.green("Writing score changed.") << "\n";
			break;
		}

		case 8:
		{
			cout << "Enter new reading score: ";
			int newReading = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].reading = newReading;
			cout << C.green("Reading score changed.") << "\n";
			break;
		}

		case 9:
		{
			cout << "Enter new other score: ";
			int newOther = getInput.getNumber();
			db.db[classroomIndex].teacher->classRoom.students[childIndex].other = newOther;
			cout << C.green("Other score changed.") << "\n";
			break;
		}
		}

		utils.waitForKeyPress();
	} while (opt != 0);

	return;
}

// void StudentRecord::editStudent()
// {
// 	utils.clear();
// 	string name;
// 	int maths;
// 	int science;
// 	int writing;
// 	int reading;
// 	int others;
// 	string learningProgress;
// 	cout << "Enter the student's name: ";
// 	name = getInput.getString();
// 	cout << "\nWhat is " << name << "'s score in maths out of 100? ";
// 	maths = getInput.getNumber();
// 	cout << "\nWhat is " << name << "'s score in science out of 100? ";
// 	science = getInput.getNumber();
// 	cout << "\nWhat is " << name << "'s score in writing out of 100? ";
// 	writing = getInput.getNumber();
// 	cout << "\nWhat is " << name << "'s score in reading out of 100? ";
// 	reading = getInput.getNumber();
// 	cout << "\nWhat is " << name << "'s score in other areas out of 100? ";
// 	others = getInput.getNumber();
// 	cout << "\nHow is " << name << " doing in terms of learning? Answer with achieved, needs help or progressing ";
// 	learningProgress = getInput.getString();
// 	if (learningProgress == "Achieved")
// 	{
// 		cout << "\nIt's good to hear that " << name << " is doing ok with their work\n";
// 	}
// 	else if (learningProgress == "Needs Help")
// 	{
// 		cout << "\n"
// 				 << name << " seems to be struggling. Maybe you should explain the material more clearly\n";
// 	}
// 	else if (learningProgress == "Progressing")
// 	{
// 		cout << "\n"
// 				 << name << " is trying hard. Keep supporting them\n";
// 	}
// 	else
// 	{
// 		cout << "\nInvalid Choice!\n";
// 		editStudent();
// 	}
// }

void StudentRecord::deleteStudent()
{
	utils.clear();

	string childName;
	optional<Student> student;
	int childClassroomNumber;

	cout << "Delete Student Record"
			 << "\n\n";

	cout << "Enter Students Name and Class:"
			 << "\n\n";
	cout << "Student's Name: ";
	childName = getInput.getString();

	cout << "Student's Class: ";
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
		cout << C.red("Student does not exist!") << "\n\n";
		utils.waitForKeyPress();
		return;
	}

	cout << "\nAre you sure you want to delete " << student->name << "'s record? ";

	cout << "\nType 'Delete' to confirm! ";
	string deleteStudent = getInput.getString();
	if (deleteStudent == "Delete")
	{

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
					db.db[i].teacher->classRoom.students.erase(db.db[i].teacher->classRoom.students.begin() + j);
					break;
				}
			}
		}

		cout << C.green("Student's Record Removed!") << "\n";
	}
	else
		cout << C.yellow("Student's Record Not Removed!") << "\n";

	utils.waitForKeyPress();
}

void StudentRecord::updateStudent()
{
	utils.clear();

	string childName;
	optional<Student> student;
	int childClassroomNumber;

	cout << "Update Student Record"
			 << "\n\n";

	cout << "Enter Students Name and Class:"
			 << "\n\n";
	cout << "Student's Name: ";
	childName = getInput.getString();

	cout << "Student's Class: ";
	childClassroomNumber = getInput.getNumber();

	bool classroomNumberExists = false;
	bool childExists = false;

	int classroomIndex = -1;
	int childIndex = -1;

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
				classroomIndex = i;
				childIndex = j;
				break;
			}
		}
	}

	if (!childExists)
	{
		cout << C.red("Student does not exist!") << "\n\n";
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

	cout << student->name << "'s current progress is " << C.blue(learningProgress)
			 << "\n\n";

	cout << "What would you like to update the students current progress to?\n";
	cout << "1. Achieved"
			 << "\n"
			 << "2. Progressing"
			 << "\n"
			 << "3. Needs Help"
			 << "\n";

	int choice = getInput.getNumber();

	switch (choice)
	{
	case 1:
		db.db[classroomIndex].teacher->classRoom.students[childIndex].learningProgress = LearningProgress::Achieved;
		break;
	case 2:
		db.db[classroomIndex].teacher->classRoom.students[childIndex].learningProgress = LearningProgress::Progressing;
		break;
	case 3:
		db.db[classroomIndex].teacher->classRoom.students[childIndex].learningProgress = LearningProgress::Need_Help;
		break;
	default:
		cout << "Invalid Choice!\n";
		utils.waitForKeyPress();
		utils.clear();
		return;
	}

	cout << "Student's Record Updated!\n";
	utils.waitForKeyPress();
}

void StudentRecord::viewStudent()
{
	utils.clear();

	string childName;
	optional<Student> student;
	int childClassroomNumber;

	cout << "View Student Record\n\n";
	cout << "Enter Students Name and Class:\n\n";
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
		cout << C.red("Student does not exist!") << "\n\n";
		utils.waitForKeyPress();
		return;
	}

	string gender;
	string learningProgress;

	if (student->gender == Gender::Male)
		gender = "Male";
	else if (student->gender == Gender::Female)
		gender = "Female";

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

	// cout << "\n\nThis is the Record for 'students name'";
	// cout << "\n\nThis is the Record for 'students name'"
	// 		 << "\n";
	cout << "Full Name: " << student->name << "\n";
	cout << "\nGender: " << gender << "\n";
	cout << "\nMaths: " << student->math << "% / 100%\n";
	cout << "\nScience: " << student->science << "% / 100%\n";
	cout << "\nWriting: " << student->writing << "% / 100%\n";
	cout << "\nReading: " << student->writing << "% / 100%\n";
	cout << "\nOthers: " << student->other << "% / 100%\n";
	cout << "\nLearning Progress: " << learningProgress << "\n";
	cout << "\n";

	utils.waitForKeyPress();
}