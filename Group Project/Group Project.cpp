#include <iostream>
#include <vector>
#include <string>

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

void displayMenu(bool logedIn = false)
{
  cout << "\n";
  cout << "Welcome to Yoobee School Info System"
       << "\n";
  cout << "\n";

  if (logedIn)
  {
    switch (db.currentUser.type)
    {
    case UserType::Admin:
      cout << "1. Admin"
           << "\n";
      break;
    case UserType::Teacher:
      cout << "1. Teacher"
           << "\n";
      break;
    case UserType::Parent:
      cout << "1. Parent"
           << "\n";
      break;
    }

    cout << "2. Logout"
         << "\n";
  }
  else
  {
    cout << "1. Login"
         << "\n";
    cout << "2. Register"
         << "\n";
  }
  cout << "3. Upcoming Events"
       << "\n";
  cout << "4. Contact Details"
       << "\n";
  cout << "5. Exit and save"
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

  Student student1 = {"bill", "bill1", "1/2/3", Gender::Male, 1, 2, 3, 4, 5, 6, "is a very bad boy"};
  Student student2 = {"bob", "bobiscool", "2/3/4", Gender::Female, 1, 2, 3, 4, 5, 6, "is a very very bad boy"};

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
  class ::Parent parent1("jill", "parentid1", "email", "10/20/30", "number", Gender::Male, _childIds);

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
        menuLogin.execute();

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
