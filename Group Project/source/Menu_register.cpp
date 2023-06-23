#include "../header/Menu_Register.h"

using namespace std;

int MenuRegister::execute()
{
	int userOccupation;

	cout << "Occupation:"
			 << "\n"
			 << "1) Teacher"
			 << "\n"
			 << "2) Parent"
			 << "\n";

	cout << "\n"
			 << "Enter your occupation: ";
	userOccupation = getInput.getNumber();

	// genral user info
	string name;
	string dob;
	string gender;
	string email;
	string username;
	string password;

	// teacher info
	int classroomNumber;
	string teachingYear;

	string contactNumber;

	switch (userOccupation)
	{
	case 1:
		cout << "Teacher Registration"
				 << "\n"
				 << "\n";
		cout << "\n"
				 << "Full Name: ";

		cout << "\n"
				 << "Gender: ";

		cout << "\n"
				 << "Date of Birth: ";

		cout << "\n"
				 << "Email: ";

		cout << "\n"
				 << "Contact Number: ";

		cout << "\n"
				 << "Classroom Number: ";

		cout << "\n"
				 << "Teaching Year(eg: year 1): ";

		cout << "\n"
				 << "Username: ";

		cout << "\n"
				 << "Password: ";

		cout << "\n";
		utils.waitForKeyPress();
		utils.clear();
		break;
	case 2:
		cout << "Parent Registration"
				 << "\n"
				 << "\n";
		cout << "\n"
				 << "Full Name: ";

		cout << "\n"
				 << "Gender: ";

		cout << "\n"
				 << "Date of Birth: ";

		cout << "\n"
				 << "Email: ";

		cout << "\n"
				 << "Contact Number: ";

		cout << "\n"
				 << "Username: ";

		cout << "\n"
				 << "Password: ";

		cout << "\n"
				 << "Add child/children:"
				 << "\n";

		bool addAnotherChild = false;
		int childCount = 1;

		vector<string> childIds;
		do
		{
		startOfLoop:

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
				goto startOfLoop;
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
				goto startOfLoop;
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
				goto startOfLoop;
				// continue;
			}

			// ! ////////////////////////////////////////////////////////

			childCount++;
			childIds.push_back(childId);

			cout << "\n"
					 << "Add another child?  ";
			addAnotherChild = getInput.getYesNo();

		} while (addAnotherChild);

		// cout << "\n"
		// 		 << "Parent/Caregiver Emergency Contact Number: ";

		Login login = {username, password};
		class ::Parent parent = {name, name + " " + dob, email, dob, childIds};
		User user(login, parent.id + " user", parent);

		cout << "\n"
				 << "Parent registration complete.";

		utils.waitForKeyPress();
		utils.clear();
		break;
	}

	return 0;
}