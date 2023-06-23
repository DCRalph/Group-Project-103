#include <iostream>

#include "header/cliTools.h"
#include "header/db.h"
#include "header/color.h"

#include "header/Menu_login.h"
#include "header/Menu_register.h"
#include "header/Menu_extra.h"
#include "header/Teacher_home_screen.h"

// #include "header/Teacher_home_screen.h"

#include "lib/json.hpp"

using json = nlohmann::json;

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
    Login NullLogin = {"", ""};
    // Login login1 = {"admin", "admin", UserType::Admin, "admin user"};
    // Login login2 = {"user", "user", UserType::Parent, "normal user"};

    User NullUser = {NullLogin, UserType::NullUser, "null user"};
    // User item1 = {login1};
    // User item2 = {login2};

    db.push_back(NullUser);
    // db.push_back(item1);
    // db.push_back(item2);

    currentlyLogedinUser = NullUser;

    // cerate a test admin user
    ///////////////////////////////////////////////////////

    Login adminLogin1 = {"admin", "admin"};

    class ::Admin admin1 = {"bob", "adminid1"};

    User user1 = {adminLogin1, UserType::Admin, "admin user1"};
    user1.admin = admin1;

    db.push_back(user1);

    ///////////////////////////////////////////////////////

    // cerate a test class

    Student student1 = {"bill", "bill1", "1/2/3", Male, 1, 2, 3, 4, 5, 6, "is a very bad boy"};

    vector<Student> vec = {student1};

    ClassRoom class1 = {vec, 69};

    ///////////////////////////////////////////////////////

    // cerate a test teacher user

    Login teacher1 = {"teacher", "teacher"};

    class ::Teacher teacher2 = {"jill", "wenier", class1};

    User user3 = {teacher1, UserType::Teacher, "teacher user1"};

    db.push_back(user3);

    ///////////////////////////////////////////////////////

    // cerate a test parent user

    Login parent1 = {"parent", "parent"};

    vector<string> vec2 = {"bill1"};

    class ::Parent parent2 = {"jill", "parentid1", "email", "dob", vec2};

    User user2 = {parent1, UserType::Parent, "parent user1"};
    user2.parent = parent2;

    db.push_back(user2);

    ///////////////////////////////////////////////////////

    MenuLogin MenuLogin;
    MenuRegister MenuRegister;
    MenuExtra MenuExtra;
    TeacherMenu TeacherMenu;

    int choice;

    do
    {
        // utils.clear();
        bool logedIn = currentlyLogedinUser.type != UserType::NullUser;

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

    json data = {
        {"admins", json::array()},
        {"parents", json::array()},
        {"teachers", json::array()},
        {"students", json::array()},

    };

    json childIds = json::array();

    for (int i = 0; i < db.size(); i++)
    {
        if (db[i].type == UserType::NullUser)
        {
            continue;
        }
        switch (db[i].type)
        {
        case UserType::Admin:
            data["admins"].push_back({
                {"username", db[i].login.username},
                {"password", db[i].login.password},
                {"type", db[i].type},
                {"name", db[i].admin.name},
                {"id", db[i].admin.id},

            });
            break;

        case UserType::Parent:

            // json childIds = json::array();
            childIds = json::array();

            for (int j = 0; i < db[i].parent.childIds.size(); i++)
            {
                childIds.push_back({
                    {"id", db[i].parent.childIds[j]},
                });
            }

            data["parents"].push_back({
                {"username", db[i].login.username},
                {"password", db[i].login.password},
                {"type", db[i].type},
                {"name", db[i].parent.name},
                {"id", db[i].parent.id},
                {"children", childIds},
            });

            break;
        case UserType::Teacher:

            data["teachers"].push_back({
                {"username", db[i].login.username},
                {"password", db[i].login.password},
                {"type", db[i].type},
                {"name", db[i].teacher.name},
                {"id", db[i].teacher.id},
                {"classRoomNumber", db[i].teacher.classRoom.classRoomNumber},
            });

            for (int j = 0; i < db[i].teacher.classRoom.students.size(); i++)
            {
                data["students"].push_back({
                    {"name", db[i].teacher.classRoom.students[j].name},
                    {"id", db[i].teacher.classRoom.students[j].id},
                    {"dob", db[i].teacher.classRoom.students[j].dob},
                    {"gender", db[i].teacher.classRoom.students[j].gender},

                    {"math", db[i].teacher.classRoom.students[j].math},
                    {"science", db[i].teacher.classRoom.students[j].science},
                    {"english", db[i].teacher.classRoom.students[j].english},
                    {"writing", db[i].teacher.classRoom.students[j].writing},
                    {"reading", db[i].teacher.classRoom.students[j].reading},
                    {"other", db[i].teacher.classRoom.students[j].other},

                    {"learningProgress", db[i].teacher.classRoom.students[j].learningProgress},
                });
            }

            break;
        }
    }

    cout << data.dump(4) << endl;

    cout << ("Exiting...") << "\n";
}
