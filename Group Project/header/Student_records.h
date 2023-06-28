#pragma once

#include <iostream>
#include <optional>

#include "cliTools.h"
#include "db.h"

#include "Menu_Register.h"

class StudentRecord
{

public:
	int execute();
	void addStudent();
	void editStudent();
	void deleteStudent();
	void updateStudent();
	void viewStudent();
};