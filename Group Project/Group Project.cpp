#include "header/config.h"

#include "header/Menu_login.h"
#include "header/Menu_register.h"
#include "header/Menu_event.h"
#include "header/Menu_contact.h"
// #include "header/Teacher_home_screen.h"

// By Jacob Rosner, Arthur Werner and William Giles

void displayMenu(bool logedIn = false)
{
    cout << "Menu:" << endl;
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

    MenuLogin MenuLogin;
    MenuRegister MenuRegister;
    MenuEvent MenuEvent;
    MenuContact MenuContact;
    // TeacherMenu TeacherMenu;

    int choice;

    do
    {
        utils.clear();
        bool logedIn = currentlyLogedinUser.login.type != UserType::NullUser;

        displayMenu(logedIn);

        cout << "Enter a number: ";
        choice = getInput.getNumber(C.Green);

        switch (choice)
        {
        case 1:
            if (logedIn)
                currentlyLogedinUser = NullUser;
            else
                MenuLogin.execute();

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
            MenuEvent.execute();
            break;
        case 4:
            MenuContact.execute();
            break;
        }

    } while (choice != 5);

    cout << C.brightRed("Exiting...") << "\n";
}
