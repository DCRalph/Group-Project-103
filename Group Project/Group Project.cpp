#include <iostream>

#include "header/cliTools.h"
#include "header/db.h"
#include "header/color.h"

#include "header/Menu_login.h"
#include "header/Menu_register.h"
#include "header/Menu_extra.h"
#include "header/Teacher_home_screen.h"

// #include "header/Teacher_home_screen.h"

// By Jacob Rosner, Arthur Werner and William Giles

void displayMenu(bool logedIn = false)
{
    cout << "\nWelcome to Yoobee School Info System:\n\n";
    if (logedIn)
    {
        cout << "1. Logout" << endl;
        cout << "2. " << endl;
    }
    else
    {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
    }
    cout << "3. Upcoming Events" << endl;
    cout << "4. Contact Details" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    // Login NullLogin = {"", "", UserType::NullUser, ""};
    // Login login1 = {"admin", "admin", UserType::Admin, "admin user"};
    // Login login2 = {"user", "user", UserType::Parent, "normal user"};

    // User NullUser = {NullLogin};
    // User item1 = {login1};
    // User item2 = {login2};

    // db.push_back(NullUser);
    // db.push_back(item1);
    // db.push_back(item2);

    // currentlyLogedinUser = NullUser;

    Login NullLogin = {"", "", UserType::NullUser, ""};
    Login login1 = {"admin", "admin", UserType::Admin, "admin user"};
    Login login2 = {"user", "user", UserType::Parent, "normal user"};

    User NullUser = {NullLogin};
    User item1 = {login1};
    User item2 = {login2};

    db.push_back(NullUser);
    db.push_back(item1);
    db.push_back(item2);

    currentlyLogedinUser = NullUser;

    MenuLogin menuLogin;
    MenuRegister MenuRegister;
    MenuExtra MenuExtra;
    TeacherMenu TeacherMenu;
    

    int choice;

    do
    {
        utils.clear();
        bool logedIn = currentlyLogedinUser.login.type != UserType::NullUser;

        displayMenu(logedIn);

        cout << "\nEnter a number: ";
        choice = getInput.getNumber();

        switch (choice)
        {
        case 1:
            if (logedIn)
                currentlyLogedinUser = NullUser;
            else
                menuLogin.execute();

            break;
        case 2:
            if (logedIn)
            {
                cout << "You are already logged in!" << endl;
                utils.waitForKeyPress();
            }
            else
                MenuRegister.execute();

            break;
        case 3:
            MenuExtra.execute(choice);
            break;
        case 4:
            MenuExtra.execute(choice);
            break;
        }

    } while (choice != 5);

    cout << ("Exiting...") << "\n";
}
