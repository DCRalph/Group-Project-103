#include "../header/db.h"

using namespace std;

Login::Login()
{
  username = "";
  password = "";
}

Login::Login(string _username, string _password)
{
  username = _username;
  password = _password;
}

Admin::Admin(string _name, string _id)
{
  name = _name;
  id = _id;
}

Student::Student(string _name, string _id, string _dob, Gender _gender, float _math, float _science, float _english, float _writing, float _reading, float _other, string _learningProgress)
{
  name = _name;
  id = _id;
  dob = _dob;
  gender = _gender;
  math = _math;
  science = _science;
  english = _english;
  writing = _writing;
  reading = _reading;
  other = _other;
  learningProgress = _learningProgress;
}

Student::Student(string _name, string _dob, Gender _gender)
{
  name = _name;
  id = _name + " " + _dob;
  dob = _dob;
  gender = _gender;
  math = 0;
  science = 0;
  english = 0;
  writing = 0;
  reading = 0;
  other = 0;
  learningProgress = "";
}

ClassRoom::ClassRoom()
{
}

ClassRoom::ClassRoom(int _classRoomNumber, string _yearLevel)
{
  classRoomNumber = _classRoomNumber;
  yearLevel = _yearLevel;
}

Teacher::Teacher(string _name, string _id, string _email, string _dob, string _contactNumber, Gender _gender, ClassRoom _classRoom)
{
  name = _name;
  id = _id;
  dob = _dob;
  email = _email;
  contactNumber = _contactNumber;
  gender = _gender;
  // teachingYear = _teachingYear;

  classRoom = _classRoom;
}

User::User()
{
  type = UserType::NullUser;
  id = "NullUser";
}

User::User(Login _login, string _id, class ::Admin _admin)
{
  login = _login;
  type = UserType::Admin;
  id = _id;
  admin = _admin;
}

User::User(Login _login, string _id, class ::Parent _parent)
{
  login = _login;
  type = UserType::Parent;
  id = _id;
  parent = _parent;
}

User::User(Login _login, string _id, class ::Teacher _teacher)
{
  login = _login;
  type = UserType::Teacher;
  id = _id;
  teacher = _teacher;
}

string User::getName()
{
  switch (type)
  {
  case UserType::Admin:
    return admin->name;
    break;
  case UserType::Parent:
    return parent->name;
    break;
  case UserType::Teacher:
    return teacher->name;
    break;

  default:
    return "[NullUser]";
    break;
  }
}

Parent::Parent(string _name, string _id, string _email, string _dob, string _contactNumber, Gender _gender, vector<string> _childIds)
{
  name = _name;
  id = _id;
  email = _email;
  dob = _dob;
  gender = _gender;
  contactNumber = _contactNumber;
  childIds = _childIds;
}

void DataBase::load()
{
  ifstream dataFile(SAVEFILE);

  if (dataFile.good())
  {
    json data;
    dataFile >> data;

    for (auto &item : data["admins"])
    {
      Login login = {item["username"], item["password"]};
      class ::Admin admin = {item["name"], item["id"]};
      User user(login, item["id"], admin);
      db.push_back(user);
    }

    for (auto &item : data["parents"])
    {
      vector<string> _childIds;
      for (auto &_childId : item["children"])
      {
        string _id = _childId["id"];
        _childIds.push_back(_id);
      }

      Login login = {item["username"], item["password"]};
      class ::Parent parent(item["name"], item["id"], item["email"], item["dob"], item["contactNumber"], Gender(item["gender"]), _childIds);
      User user(login, item["id"], parent);
      db.push_back(user);
    }

    for (auto &item : data["teachers"])
    {
      vector<Student> _students;

      for (auto &_student : item["students"])
      {
        Student _newStudent(_student["name"], _student["id"], _student["dob"], Gender(_student["gender"]), _student["math"], _student["science"], _student["english"], _student["writing"], _student["reading"], _student["other"], _student["learningProgress"]);
        _students.push_back(_newStudent);
      }

      ClassRoom class1(item["classRoomNumber"], item["yearLevel"]);
      class1.students = _students;

      Login login(item["username"], item["password"]);
      class ::Teacher teacher(item["name"], item["id"], item["email"], item["dob"], item["contactNumber"], Gender(item["gender"]), class1);
      User user(login, item["id"], teacher);
      db.push_back(user);
    }
  }
}

void DataBase::save()
{

  json data = {
      {"admins", json::array()},
      {"parents", json::array()},
      {"teachers", json::array()},
  };

  json childIds = json::array();
  json students = json::array();

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
          {"name", db[i].admin->name},
          {"id", db[i].admin->id},

      });
      break;

    case UserType::Parent:

      childIds = json::array();

      for (int j = 0; j < db[i].parent->childIds.size(); j++)
      {
        childIds.push_back({
            {"id", db[i].parent->childIds[j]},
        });
      }

      data["parents"].push_back({{"username", db[i].login.username},
                                 {"password", db[i].login.password},
                                 {"name", db[i].parent->name},
                                 {"id", db[i].parent->id},
                                 {"email", db[i].parent->email},
                                 {"dob", db[i].parent->dob},
                                 {"children", childIds},
                                 {"contactNumber", db[i].parent->contactNumber},
                                 {"gender", db[i].parent->gender}});

      break;
    case UserType::Teacher:

      students = json::array();

      for (int j = 0; j < db[i].teacher->classRoom.students.size(); j++)
      {
        students.push_back({
            {"name", db[i].teacher->classRoom.students[j].name},
            {"id", db[i].teacher->classRoom.students[j].id},
            {"dob", db[i].teacher->classRoom.students[j].dob},
            {"gender", db[i].teacher->classRoom.students[j].gender},

            {"math", db[i].teacher->classRoom.students[j].math},
            {"science", db[i].teacher->classRoom.students[j].science},
            {"english", db[i].teacher->classRoom.students[j].english},
            {"writing", db[i].teacher->classRoom.students[j].writing},
            {"reading", db[i].teacher->classRoom.students[j].reading},
            {"other", db[i].teacher->classRoom.students[j].other},

            {"learningProgress", db[i].teacher->classRoom.students[j].learningProgress},
        });
      }

      data["teachers"].push_back({
          {"username", db[i].login.username},
          {"password", db[i].login.password},
          {"name", db[i].teacher->name},
          {"id", db[i].teacher->id},
          {"classRoomNumber", db[i].teacher->classRoom.classRoomNumber},
          {"students", students},
          {"yearLevel", db[i].teacher->classRoom.yearLevel},
          {"email", db[i].teacher->email},
          {"dob", db[i].teacher->dob},
          {"contactNumber", db[i].teacher->contactNumber},
          {"gender", db[i].teacher->gender} //
                                            // {"teachingYear", db[i].teacher->teachingYear}

      });

      break;
    }
  }

  // std::cout << data.dump(2) << "\n";

  ofstream file;
  file.open(SAVEFILE, ios::out | ios::trunc);
  file << data.dump(2);
  file.close();
}

DataBase db;
