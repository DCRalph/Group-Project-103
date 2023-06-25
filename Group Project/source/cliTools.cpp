#include "../header/cliTools.h"
#include <string>

using namespace std;

string GetInput::getString(string _color, string _pre)
{
  cout << _color << _pre;

  cin.clear();
  string input = "";
  getline(cin, input);

  if (input.length() == 0)
  {
    // cout << Col.red("Invalid input. Please enter a string: ");
    cout << ("Invalid input. Please enter a string: ");

    input = getString(_color, _pre);
  }

  return input;
}

double GetInput::getNumber(string _color, string _pre)
{
  cout << _color << _pre;

  cin.clear();
  string input;
  getline(cin, input);

  double number = 0;

  try
  {
    number = stod(input);
  }
  catch (const exception &e)
  {
    cout << ("Invalid input. Please enter a number: ");
    // cout << Col.red("Invalid input. Please enter a number: ");

    number = getNumber(_color, _pre);
  }

  return number;
}

bool GetInput::getYesNo(bool _default)
{
  // cout << (_default) ? C.yellow("(") + C.green("Y") + C.yellow("/") + C.red("n") + C.yellow("): ") : C.yellow("(") + C.green("y") + C.yellow("/") + C.red("N") + C.yellow("): ");

  if (_default)
    cout << "(Y/n): ";
  else
    cout << "(y/N): ";

  /*if (_default)
      cout << C.yellow("(") + C.green("Y") + C.yellow("/") + C.red("n") + C.yellow("): ");
  else
      cout << C.yellow("(") + C.green("y") + C.yellow("/") + C.red("N") + C.yellow("): ");*/

  cin.clear();
  string input;
  getline(cin, input);

  if (input.length() == 0)
  {
    return _default;
  }

  if (input == "Y" || input == "y")
  {
    return true;
  }
  else if (input == "N" || input == "n")
  {
    return false;
  }
  else
  {
    cout << ("Invalid input. Please enter ");

    if (_default)
      cout << "(Y/n): ";
    else
      cout << "(y/N): ";

    /*else
    {
        cout << C.red("Invalid input. Please enter ");

        if (_default)
            cout << C.yellow("(") + C.green("Y") + C.yellow("/") + C.red("n") + C.yellow("): ");
        else
            cout << C.yellow("(") + C.green("y") + C.yellow("/") + C.red("N") + C.yellow("): ");
            */
    return getYesNo(_default);
  }
}

void Utils::clear() // clear the console
{
#if defined _WIN32
  system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)
  system("clear");
#endif
}

void Utils::waitForKeyPress()
{
  cout << ("Press any key to continue...");
  // cout << Col.yellow("Press any key to continue...");
  cin.get();
}

GetInput getInput;
Utils utils;
