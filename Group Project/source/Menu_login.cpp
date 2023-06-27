#include "../header/Menu_Login.h"

using namespace std;

int MenuLogin::execute()
{

  string username, password;

  utils.clear();

  cout << "\n"
       //  << "Login"
       << C.brightMagenta("Login")
       << "\n"
       << "Type \"exit\" to go back to the main menu."
       << "\n"
       << "\n";

  cout << "Enter username: ";
  username = getInput.getString();

  if (username == "exit")
    return 2;

  // TODO - hide password

  cout << "Enter password: ";
  password = getInput.getString();

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
      // cout << C.red("Invalid password!") << "\n";

      // db.db[i].attempts++;

      utils.waitForKeyPress();

      continue;
    }

    cout << "\n";
    cout << ("Logged in!") << "\n";

    cout << "Welcome, " << db.db[i].getName() << "!"
         << "\n";
    cout << "\n";

    db.currentUser = db.db[i];

    utils.waitForKeyPress();

    return 1;
  }

  cout << ("Invalid username or password!") << "\n";
  utils.waitForKeyPress();

  return 0;
}