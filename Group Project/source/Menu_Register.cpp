#include "../header/Menu_Register.h"

using namespace std;

int MenuRegister::execute()
{
	utils.clear();
	int userOccupation;

	cout << "\n"
			 //  << "Register"
			 << C.brightMagenta("Register")
			 << "\n"
			 << "\n";

	// cout << "Occupation:"
	// 		 << "\n"
	// 		 << "1. Parent"
	// 		 << "\n"
	// 		 << "2. Teacher"
	// 		 << "\n"
	// 		 << "3. Exit"
	// 		 << "\n";

	cout << "Occupation:"
			 << "\n";

	cout << C.red("0.") << " Exit\n";
	cout << C.cyan("1.") << " Parent\n";
	cout << C.cyan("2.") << " Teacher\n";

	cout << "\n"
			 << "Enter your occupation: ";
	userOccupation = getInput.getNumber();

	switch (userOccupation)
	{
	case 0:
		break;
	case 1:
		this->registerParent();
		break;
	case 2:
		this->registerTeacher();
		break;
	default:
		utils.clear();
		cout << "\n";
		cout << C.red("Invalid input, please try again.") << "\n\n";

		utils.waitForKeyPress();
	}

	return 0;
}

void MenuRegister::registerParent()
{
	int children = 0;
	for (int i = 0; i < db.db.size(); i++)
	{

		if (db.db[i].type == UserType::Teacher)
		{
			children += db.db[i].teacher->classRoom.students.size();
		}

		if (db.db[i].type == UserType::Parent)
		{
			children -= db.db[i].parent->childIds.size();
		}
	}

	if (children == 0)
	{
		cout << "There are no children to register. Please contact the school administration for more information."
				 << "\n";
		utils.waitForKeyPress();
		return;
	}

	cout << "There are " << children << " children available to register."
			 << "\n";

	string name;
	string dob;
	int gender;
	string email;
	string username;
	string password;
	string contactNumber;
	string emergencyContactNumber;

	Gender genderEnum;

	cout << "Parent Registration"
			 << "\n"
			 << "\n";
	cout << "Name: ";
	name = getInput.getString();

	bool validGender = true;
	do
	{
		cout << "Gender:"
				 << "\n"
				 << C.cyan("1.") << " Male"
				 << "\n"
				 << C.cyan("2.") << " Female"
				 << "\n"
				 << "Enter your choice: ";

		gender = getInput.getNumber();

		validGender = gender >= 1 && gender <= 2;

		if (validGender)
			genderEnum = Gender(gender - 1);

		if (!validGender)
			cout << C.red("Invalid gender. Please try again.") << "\n";

	} while (!validGender);

	cout << "Date of Birth: ";
	dob = getInput.getString();

	cout << "Email: ";
	email = getInput.getString();

	cout << "Contact Number: ";
	contactNumber = getInput.getString();

	cout << "Emergency Contact Number : ";
	emergencyContactNumber = getInput.getString();

	cout << "\n"
			 << "Username: ";
	username = getInput.getString();

	cout << "Password: ";
	password = getInput.getString();

	cout << "\n"
			 << "Add child/children:"
			 << "\n";

	bool addAnotherChild = false;
	int childCount = 1;

	vector<string> childIds;
	do
	{

		string childName;
		int childClassroomNumber;

		cout << "\n"
				 << "Child " << childCount << ": "
				 << "\n";

		cout << "Child's Name: ";

		childName = getInput.getString();

		cout << "Child Classroom Number: ";

		childClassroomNumber = getInput.getNumber();

		// ! ////////////////////////////////////////////////////////////
		bool classroomNumberExists = false;
		bool childExists = false;
		bool childAlreadyAsigned = false;
		string childId;

		// check if classroom number exists

		for (int i = 0; i < db.db.size(); i++)
		{

			if (db.db[i].type != UserType::Teacher)
				continue;

			if (db.db[i].teacher->classRoom.classRoomNumber == childClassroomNumber)
			{
				classroomNumberExists = true;
				break;
			}
		}

		if (!classroomNumberExists)
		{
			cout << "\n"
					 << C.red("Classroom number does not exist!")
					 << "\n";

			utils.waitForKeyPress();
			goto skipToEnd;
			// continue;
		}

		// ! ////////////////////////////////////////////////////////////

		// check if child exists

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
					childId = db.db[i].teacher->classRoom.students[j].id;
					break;
				}
			}
		}

		if (!childExists)
		{
			cout << "\n"
					 << C.red("Child does not exist!")
					 << "\n";

			utils.waitForKeyPress();
			goto skipToEnd;
			// continue;
		}

		// ! ////////////////////////////////////////////////////////

		for (int i = 0; i < db.db.size(); i++)
		{

			if (db.db[i].type != UserType::Parent)
				continue;

			for (int j = 0; j < db.db[i].parent->childIds.size(); j++)
			{
				if (db.db[i].parent->childIds[j] == childId)
				{
					childAlreadyAsigned = true;
					break;
				}
			}
		}

		if (childAlreadyAsigned)
		{
			cout << "\n"
					 << C.red("Child already asigned to another parent!")
					 << "\n";

			utils.waitForKeyPress();
			goto skipToEnd;
			// continue;
		}

		// ! ////////////////////////////////////////////////////////

		childCount++;
		childIds.push_back(childId);

	skipToEnd:

		cout << "\n"
				 << "Add another child?  ";
		addAnotherChild = getInput.getYesNo();

	} while (addAnotherChild);

	// cout << "\n"
	// 		 << "Parent/Caregiver Emergency Contact Number: ";

	if (childIds.size() == 0)
	{
		cout << "\n"
				 << C.red("No children added. Registration cancelled.")
				 << "\n";

		utils.waitForKeyPress();
		utils.clear();
		return;
	}

	Login login = {username, password};
	class ::Parent parent(name, name + " " + dob, email, dob, contactNumber, emergencyContactNumber, genderEnum, childIds);
	User user(login, parent.id + " user", parent);

	db.db.push_back(user);

	cout << "\n"
			 << "Parent registration complete."
			 << "\n";

	utils.waitForKeyPress();
	utils.clear();
}

void MenuRegister::registerTeacher(int _classRoomNumber)
{
	string name;
	string dob;
	int gender;
	string email;
	string username;
	string password;
	string contactNumber;
	int classroomNumber;
	string teachingYear;

	Gender genderEnum;

	cout << "Teacher Registration"
			 << "\n"
			 << "\n";
	cout << "Name: ";
	name = getInput.getString();

	bool validGender = true;
	do
	{
		cout << "Gender:"
				 << "\n"
				 << C.cyan("1.") << " Male"
				 << "\n"
				 << C.cyan("2.") << " Female"
				 << "\n"
				 << "Enter your choice: ";

		gender = getInput.getNumber();

		validGender = gender >= 1 && gender <= 2;

		if (validGender)
			genderEnum = Gender(gender - 1);

		if (!validGender)
			cout << C.red("Invalid gender. Please try again.") << "\n";

	} while (!validGender);

	cout << "Date of Birth: ";
	dob = getInput.getString();

	cout
			<< "Email: ";
	email = getInput.getString();

	cout
			<< "Contact Number: ";
	contactNumber = getInput.getString();

	if (_classRoomNumber == -1)
	{
		cout << "Classroom Number: ";
		classroomNumber = getInput.getNumber();
	}
	else
	{
		classroomNumber = _classRoomNumber;
	}

	cout << "Teaching Year(eg: year 1): ";
	teachingYear = getInput.getString();

	cout << "\n"
			 << "Username: ";
	username = getInput.getString();

	cout << "Password: ";
	password = getInput.getString();

	for (int i = 0; i < db.db.size(); i++)
	{

		if (db.db[i].type != UserType::Teacher)
			continue;

		if (db.db[i].teacher->classRoom.classRoomNumber != classroomNumber)
			continue;

		cout << "\n"
				 << C.red("Classroom already exists! Registration cancelled.")
				 << "\n";

		utils.waitForKeyPress();

		return;
	}

	Login login(username, password);
	ClassRoom class1(classroomNumber, teachingYear);
	class ::Teacher teacher(name, name + " " + dob, email, dob, contactNumber, genderEnum, class1);
	User user(login, teacher.id + " user", teacher);

	db.db.push_back(user);

	cout << "\n";

	if (_classRoomNumber == -1)
	{
		cout << "Teacher registration complete."
				 << "\n";
		utils.waitForKeyPress();
	}
	else
		cout << "Teacher added to class."
				 << "\n";

	// utils.clear();
}