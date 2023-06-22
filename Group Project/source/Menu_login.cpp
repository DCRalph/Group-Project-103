#include "../header/Menu_login.h"

int MenuLogin::execute()
{
   AdminMenu AdminMenu;
   TeacherMenu TeacherMenu;
   ParentMenu ParentMenu;
  string username, password;

  utils.clear();

  cout << "Login" << endl
       << endl;

  cout << "Enter username: ";
  username = getInput.getString();
    
  //Temp Teacher Login
    if (username == "teacher") 
    {
        TeacherMenu.execute();
        return 0;
    }

    //Temp Admin Login
    if (username == "admin")
    {
        AdminMenu.execute();
        return 0;
    }
    //Temp Parent Login
    if (username == "parent")
    {
        ParentMenu.execute();
        return 0;
    }

  // TODO - hide password

  cout << "Enter password: ";
  password = getInput.getString();

  cout << password << endl;

  // TODO - check if username and password match
  cout << ("Logging in...") << endl;

  for (int i = 0; i < db.size(); i++)
  {
    

    if (db[i].login.type == NullUser)
    {
      continue;
    }

    if (db[i].login.username != username)
    {
      // cout << C.red(C.bold("Invalid username or password!")) << endl;

      continue;
    }

    if (db[i].attempts >= 3)
    {
      cout << ("You have exceeded the number of attempts!") << endl;

      return 0;
    }

    if (db[i].login.password != password)
    {
      cout << ("Invalid password!") << endl;

      db[i].attempts++;

      continue;
      ;
    }

    cout << ("Logged in!") << endl;

    cout << "Welcome, " << db[i].login.id << "!" << endl;

    currentlyLogedinUser = db[i];

    utils.waitForKeyPress();
    utils.clear();
    return db[i].login.type;
  }

  cout << ("Invalid username or password!") << endl;

  return 0;
}