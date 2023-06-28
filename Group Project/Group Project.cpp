#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

#include "header/cliTools.h"
#include "header/db.h"
#include "header/color.h"

#include "header/Menu_Admin.h"
#include "header/Menu_Extra.h"
#include "header/Menu_Login.h"
#include "header/Menu_Parent.h"
#include "header/Menu_Register.h"
#include "header/Menu_Teacher.h"

#include "lib/json.hpp"

using namespace std;

int incorrectLoginAttempts = 0;
chrono::system_clock::time_point lockedOutTime;

void displayMenu(bool logedIn = false)
{

  cout << "\n";
  cout << C.brightMagenta("Welcome to Yoobee School Info System")
       << "\n"
       << "\n";

  if (logedIn)
  {
    cout << ("You are logged in as: ")
         << C.brightCyan(db.currentUser.getName());
  }
  else
  {
    cout << ("You are not logged in.");
  }

  cout << "\n";

  switch (db.currentUser.type)
  {
  case UserType::Admin:
    cout << ("You are an Admin")
         << "\n";
    break;
  case UserType::Teacher:
    cout << ("You are a Teacher. Your ")
         << C.brightCyan(db.currentUser.teacher->classRoom.yearLevel)
         << (" class in room ")
         << C.brightCyan(to_string(db.currentUser.teacher->classRoom.classRoomNumber))
         << (" has ")
         << C.brightCyan(to_string(db.currentUser.teacher->classRoom.students.size()))
         << (" students.")
         << "\n";
    break;
  case UserType::Parent:
    cout << ("You are a Parent. You have ") << C.brightCyan(to_string(db.currentUser.parent->childIds.size())) << (" children. ")
         << "\n";
    break;
  }

  cout
      << "\n";

  if (logedIn)
  {
    switch (db.currentUser.type)
    {
    case UserType::Admin:
      cout << C.cyan("1.") << " Admin"
           << "\n";
      break;
    case UserType::Teacher:
      cout << C.cyan("1.") << " Teacher"
           << "\n";
      break;
    case UserType::Parent:
      cout << C.cyan("1.") << " Parent"
           << "\n";
      break;
    }

    cout << C.cyan("2.") << " Logout"
         << "\n";
  }
  else
  {
    cout << C.cyan("1.") << " Login"
         << "\n";
    cout << C.cyan("2.") << " Register"
         << "\n";
  }
  cout
      << C.cyan("3.") << " Upcoming Events"
      << "\n";
  cout << C.cyan("4.") << " Contact Details"
       << "\n";
  cout << C.cyan("5.") << " Exit and save"
       << "\n";
}

void makeTestUsers()
{

  Login adminLogin1("admin", "admin");
  class ::Admin admin1("bob", "adminid1");
  User user1(adminLogin1, "admin user1", admin1);

  // db.db.push_back(user1);
  db.db.push_back(user1);

  ///////////////////////////////////////////////////////

  // cerate a test class

  Student student1 = {"bill", "bill1", "1/2/3", Gender::Male, 1, 2, 3, 4, 5, 6, LearningProgress::Achieved};
  Student student2 = {"bob", "bobiscool", "2/3/4", Gender::Female, 1, 2, 3, 4, 5, 6, LearningProgress::Need_Help};

  vector<Student> _students{student1, student2};

  ClassRoom class1(69, "year 4");
  class1.students = _students;

  ///////////////////////////////////////////////////////

  // cerate a test teacher user

  Login teacherlogin1("teacher", "teacher");

  class ::Teacher teacher2("jill", "teacherid1", "email", "dob", "number", Gender::Male, class1);

  User user3(teacherlogin1, "teacher user1", teacher2);

  db.db.push_back(user3);

  ///////////////////////////////////////////////////////

  // cerate a test parent user

  Login parentlogin1("parent", "parent");

  vector<string> _childIds{"bill1"};

  // class ::Parent parent1 = {"jill", "parentid1", "email", "dob", _childIds};
  class ::Parent parent1("jill", "parentid1", "email", "10/20/30", "number", "emergency number", Gender::Male, _childIds);

  User user2(parentlogin1, "parent user1", parent1);

  db.db.push_back(user2);
}

int main()
{
  MenuExtra menuExtra;
  MenuLogin menuLogin;
  MenuRegister menuRegister;
  MenuTeacher menuTeacher;
  MenuParent menuParent;
  MenuAdmin menuAdmin;

  // Login login1 = {"admin", "admin", UserType::Admin, "admin user"};
  // Login login2 = {"user", "user", UserType::Parent, "normal user"};

  // User NullUser();
  // User item1 = {login1};
  // User item2 = {login2};

  // db.db.push_back(NullUser);
  // db.db.push_back(item1);
  // db.db.push_back(item2);

  db.currentUser = User();
  db.load();
  // makeTestUsers();

  db.currentUser = db.db[5]; // auto login to admin

  int choice;

  do
  {
    utils.clear();
    bool logedIn = db.currentUser.type != UserType::NullUser;

    displayMenu(logedIn);

    cout << "\nEnter a number: ";
    choice = getInput.getNumber();

    switch (choice)
    {
    case 1:
      if (logedIn)
      {
        switch (db.currentUser.type)
        {
        case UserType::Admin:
          menuAdmin.execute();
          break;
        case UserType::Teacher:
          menuTeacher.execute();
          break;
        case UserType::Parent:
          menuParent.execute();
          break;
        }
      }

      else
      {

        if (incorrectLoginAttempts >= 3)
        {
          long long msNow = chrono::system_clock::now().time_since_epoch().count();
          long long msLockedOut = lockedOutTime.time_since_epoch().count();
          long long msDiff = msNow - msLockedOut;
          msDiff = msDiff / 1000000;
          msDiff = 30 - msDiff; // 30 second timer
          // msDiff = 300 - msDiff; // 5 minute timer

          int seconds = msDiff % 60;
          int minutes = floor(msDiff / 60);

          if (msDiff > 0)
          {
            cout << "\n";
            cout << ("You have been locked out for 5 minutes.") << "\n";

            cout << "Please try again in "
                 << minutes << " minutes and "
                 << seconds << " seconds."
                 << "\n";

            utils.waitForKeyPress();
            break;
          }
          incorrectLoginAttempts = 0;
          msNow = 0;
          msLockedOut = 0;
          msDiff = 0;
        }

        if (menuLogin.execute())
        {
          incorrectLoginAttempts = 0;
        }
        else
        {
          incorrectLoginAttempts++;
          lockedOutTime = chrono::system_clock::now();
        }
      }
      break;
    case 2:
      if (logedIn)
        db.currentUser = User();

      else
        menuRegister.execute();

      break;
    case 3:
      menuExtra.displayEvent();
      break;
    case 4:
      menuExtra.displayContact();
      break;

    case 5:
      break;

    default:
      utils.clear();
      cout << "\n";
      cout << ("Invalid input, please try again.") << "\n";

      utils.waitForKeyPress();
      break;
    }
  } while (choice != 5);

  db.save();

  cout << ("Exiting...") << "\n";
}
