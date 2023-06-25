#include "../header/Menu_Register.h"

using namespace std;

int MenuRegister::execute()
{
	int userOccupation;

	cout << "Occupation:"
			 << "\n"
			 << "1. Parent"
			 << "\n"
			 << "2. Teacher"
			 << "\n";

	cout << "\n"
			 << "Enter your occupation: ";
	userOccupation = getInput.getNumber();

	if (userOccupation == 1)
		this->registerParent();

	else if (userOccupation == 2)
		this->registerTeacher();

	else
		cout << "Invalid input";

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
	string gender;
	string email;
	string username;
	string password;
	string contactNumber;

	Gender genderEnum;

	cout << "Parent Registration"
			 << "\n"
			 << "\n";
	cout << "\n"
			 << "Full Name: ";
	name = getInput.getString();

	bool validGender = true;
	do
	{
		cout << "\n"
				 << "Gender: ";
		gender = getInput.getString();

		for (int i = 0; i < gender.size(); i++)
		{
			gender[i] = tolower(gender[i]);
		}

		validGender = true;

		if (gender == "male")
			genderEnum = Gender::Male;
		else if (gender == "female")
			genderEnum = Gender::Female;
		else
			validGender = false;

		if (!validGender)
		{
			cout << ("Invalid gender. Please try again.") << "\n";
			// cout << C.red("Invalid gender. Please try again.") << "\n";
		}

	} while (!validGender);

	cout << "\n"
			 << "Date of Birth: ";
	dob = getInput.getString();

	cout << "\n"
			 << "Email: ";
	email = getInput.getString();

	cout << "\n"
			 << "Contact Number: ";
	contactNumber = getInput.getString();

	cout << "\n"
			 << "Username: ";
	username = getInput.getString();

	cout << "\n"
			 << "Password: ";
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

		cout
				<< "Child Full Name: ";

		childName = getInput.getString();

		cout << "\n"
				 << "Child Classroom Number: ";

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
					 << "Classroom number does not exist!"
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
					 << "Child does not exist!"
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
					 << "Child already asigned to another parent!"
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
				 << "No children added. Registration cancelled."
				 << "\n";

		utils.waitForKeyPress();
		utils.clear();
		return;
	}

	Login login = {username, password};
	class ::Parent parent(name, name + " " + dob, email, dob, contactNumber, genderEnum, childIds);
	User user(login, parent.id + " user", parent);

	db.db.push_back(user);

	cout << "\n"
			 << "Parent registration complete."
			 << "\n";

	utils.waitForKeyPress();
	utils.clear();
}

void MenuRegister::registerTeacher()
{
	string name;
	string dob;
	string gender;
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
	cout << "\n"
			 << "Full Name: ";
	name = getInput.getString();

	bool validGender = true;
	do
	{
		cout << "\n"
				 << "Gender: ";
		gender = getInput.getString();

		for (int i = 0; i < gender.size(); i++)
		{
			gender[i] = tolower(gender[i]);
		}

		validGender = true;

		if (gender == "male")
			genderEnum = Gender::Male;
		else if (gender == "female")
			genderEnum = Gender::Female;
		else
			validGender = false;

		if (!validGender)
		{
			cout << ("Invalid gender. Please try again.") << "\n";
			// cout << C.red("Invalid gender. Please try again.") << "\n";
		}

	} while (!validGender);

	cout << "\n"
			 << "Date of Birth: ";
	dob = getInput.getString();

	cout << "\n"
			 << "Email: ";
	email = getInput.getString();

	cout << "\n"
			 << "Contact Number: ";
	contactNumber = getInput.getString();

	cout << "\n"
			 << "Classroom Number: ";
	classroomNumber = getInput.getNumber();

	cout << "\n"
			 << "Teaching Year(eg: year 1): ";
	teachingYear = getInput.getString();

	cout << "\n"
			 << "Username: ";
	username = getInput.getString();

	cout << "\n"
			 << "Password: ";
	password = getInput.getString();

	Login login(username, password);
	ClassRoom class1(classroomNumber, teachingYear);
	class ::Teacher teacher(name, name + " " + dob, email, dob, contactNumber, genderEnum, class1);
	User user(login, teacher.id + " user", teacher);

	db.db.push_back(user);

	cout << "\n";
	utils.waitForKeyPress();
	utils.clear();
}