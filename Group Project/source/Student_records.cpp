#include "../header/Student_records.h"

using namespace std;

int StudentRecord::execute()
{
	utils.clear();
	int opt;
	cout << "Student Records\n\n";
	cout << "1) Add Student\n";
	cout << "2) Edit student Record\n";
	cout << "3) Delete Student Record\n";
	cout << "4) Update Record\n";
	cout << "5) View the Records\n";
	cout << "Enter a number: ";
	opt = getInput.getNumber();
	if (opt == 1)
	{
		// addStudent();
		// this->addStudent();
	}
	else if (opt == 2)
	{
		// editRecords();
		// this->editStudent();
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

// void StudentRecord::addStudent()
//{

//}

void StudentRecord::editStudent()
{
	utils.clear();
	string name;
	int maths;
	int science;
	int writing;
	int reading;
	int others;
	string learningProgress;
	cout << "Enter the student's name: ";
	name = getInput.getString();
	cout << "\nWhat is " << name << "'s score in maths out of 100? ";
	maths = getInput.getNumber();
	cout << "\nWhat is " << name << "'s score in science out of 100? ";
	science = getInput.getNumber();
	cout << "\nWhat is " << name << "'s score in writing out of 100? ";
	writing = getInput.getNumber();
	cout << "\nWhat is " << name << "'s score in reading out of 100? ";
	reading = getInput.getNumber();
	cout << "\nWhat is " << name << "'s score in other areas out of 100? ";
	others = getInput.getNumber();
	cout << "\nHow is " << name << " doing in terms of learning? Answer with achieved, needs help or progressing ";
	learningProgress = getInput.getString();
	if (learningProgress == "Achieved")
	{
		cout << "\nIt's good to hear that " << name << " is doing ok with their work\n";
	}
	else if (learningProgress == "Needs Help")
	{
		cout << "\n"
				 << name << " seems to be struggling. Maybe you should explain the material more clearly\n";
	}
	else if (learningProgress == "Progressing")
	{
		cout << "\n"
				 << name << " is trying hard. Keep supporting them\n";
	}
	else
	{
		cout << "\nInvalid Choice!\n";
		editStudent();
	}
}

void StudentRecord::deleteStudent()
{
	utils.clear();
	string deleteStudent;
	cout << "Delete Student Record\n\n";
	cout << "Enter Students Name and Class:\n\n";
	// TODO Take user's input to check with current data
	cout << "Student's Name: ";

	cout << "\nStudent's Class: ";

	// TODO Add if statement to check if that student exists

	// TODO Else if student does exsist
	cout << "\nType 'Delete' to confirm! ";
	deleteStudent = getInput.getString();
	if (deleteStudent == "delete")
	{
		// TODO Removes student from the files/database
		cout << "Student's Record Removed!\n";
	}
	else
	{
		cout << "Student's Record Not Removed!\n";
	}
	utils.waitForKeyPress();
	utils.clear();
}

void StudentRecord::updateStudent()
{
	utils.clear();
	cout << "Update Student Record\n\n";
	cout << "Enter Students Name and Class:\n\n";
	// TODO Take user's input to check with current data
	cout << "Student's Name: ";

	cout << "\nStudent's Class: ";
	// TODO Add if statement to check if that student exists

	// TODO Else if student does exsist
	cout << "\nWhat would you like to update the students current progress to?\n";
	cout << "1) Achieved\n2) Progressing\n3) Needs Help\n";
	utils.waitForKeyPress();
	utils.clear();
}

void StudentRecord::viewStudent()
{
	utils.clear();
	cout << "View Student Record\n\n";
	cout << "Enter Students Name and Class:\n\n";
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
	utils.waitForKeyPress();
	utils.clear();
}