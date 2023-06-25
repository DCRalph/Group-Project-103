#include "../header/Menu_Login.h"

using namespace std;

int MenuLogin::execute()
{

  string username, password;

  utils.clear();

  cout << "Login" << "\n"
       << "\n";

  cout << "Enter username: ";
  username = getInput.getString();

  // Temp Teacher Login
  // if (username == "teacher")
  // {
  //   TeacherMenu.execute();
  //   return 0;
  // }

  // // Temp Admin Login
  // if (username == "admin")
  // {
  //   AdminMenu.execute();
  //   return 0;
  // }
  // // Temp Parent Login
  // if (username == "parent")
  // {
  //   ParentMenu.execute();
  //   return 0;
  // }

  // TODO - hide password

  cout << "Enter password: ";
  password = getInput.getString();

  // TODO - check if username and password match

  for (int i = 0; i < db.db.size(); i++)
  {

    if (db.db[i].type == NullUser)
      continue;

    if (db.db[i].login.username != username)
      continue;

    // if (db.db[i].attempts >= 3)
    // {
    //   cout << ("You have exceeded the number of attempts!") << "\n";

    //   return 0;
    // }

    if (db.db[i].login.password != password)
    {
      cout << ("Invalid password!") << "\n";
      //cout << C.red("Invalid password!") << "\n";

      // db.db[i].attempts++;

      utils.waitForKeyPress();

      continue;
    }

    cout << "\n";
    cout << ("Logged in!") << "\n";

    cout << "Welcome, " << db.db[i].getName() << "!" << "\n";
    cout << "\n";

    db.currentUser = db.db[i];

    utils.waitForKeyPress();

    return db.db[i].type;
  }

  cout << ("Invalid username or password!") << "\n";

  return 0;
}