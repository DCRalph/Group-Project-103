#pragma once

#include <vector>
#include <string>

using namespace std;

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
  string name;
  string id;
};

class Student
{
public:
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

  vector<string> childrenIds;
};

class Admin
{
public:
  string name;
  string id;
};

class User
{
public:
  Login login;
  int type;
  string id;

  class ::Parent parent;
  class ::Teacher teacher;
  class ::Admin admin;
};

extern vector<User> db;
extern User currentlyLogedinUser;