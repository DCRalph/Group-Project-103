#pragma once

#include <vector>
#include <string>
#include <optional>
#include <fstream>

#include "../lib/json.hpp"

using json = nlohmann::json;

using namespace std;

const string SAVEFILE = "save.json";

enum UserType
{
  NullUser,
  Admin,
  Teacher,
  Parent,
};

enum Gender
{
  Male,
  Female
};

class Login
{
public:
  string username;
  string password;
};

class Admin
{
public:
  string name;
  string id;
};

class Student
{
public:
  Student(string _name, string _id, string _dob, Gender _gender, float _math, float _science, float _english, float _writing, float _reading, float _other, string _learningProgress);
  Student(string _name, string _dob, Gender _gender);
  string name;
  string id;
  string dob;
  Gender gender;

  float math;
  float science;
  float english;
  float writing;
  float reading;
  float other;

  string learningProgress;
};

class ClassRoom
{
public:
  vector<Student> students;
  int classRoomNumber;
};

class Teacher
{
public:
  Teacher(string _name, string _id, ClassRoom _classRoom);

  string name;
  string id;
  ClassRoom classRoom;
};

class Parent
{
public:
  string name;
  string id;
  string email;
  string dob;

  vector<string> childIds;
};

class User
{
public:
  User();
  User(Login _login, string _id, class ::Admin _admin);
  User(Login _login, string _id, class ::Parent _parent);
  User(Login _login, string _id, class ::Teacher _teacher);

  Login login;
  int type;
  string id;

  string getName();

  optional<class ::Admin> admin;
  optional<class ::Parent> parent;
  optional<class ::Teacher> teacher;
};

class DataBase
{
public:
  void load();
  void save();

  vector<User> db;
  User currentUser;
};

extern DataBase db;

// extern vector<User> db;
// extern User currentUser;