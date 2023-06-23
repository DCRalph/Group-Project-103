#include "../header/Menu_Login.h"

int MenuLogin::execute()
{

  string username, password;

  utils.clear();

  cout << "Login" << endl
       << endl;

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

  cout << password << endl;

  // TODO - check if username and password match
  cout << ("Logging in...") << endl;

  for (int i = 0; i < db.db.size(); i++)
  {

    if (db.db[i].type == NullUser)
      continue;

    if (db.db[i].login.username != username)
      continue;

    // if (db.db[i].attempts >= 3)
    // {
    //   cout << ("You have exceeded the number of attempts!") << endl;

    //   return 0;
    // }

    if (db.db[i].login.password != password)
    {
      cout << ("Invalid password!") << endl;

      // db.db[i].attempts++;

      continue;
    }

    cout << ("Logged in!") << endl;

    cout << "Welcome, " << db.db[i].getName() << "!" << endl;

    db.currentUser = db.db[i];

    utils.waitForKeyPress();
    utils.clear();
    return db.db[i].type;
  }

  cout << ("Invalid username or password!") << endl;

  return 0;
}