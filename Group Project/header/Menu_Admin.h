#pragma once

#include <iostream>

#include "cliTools.h"
#include "db.h"

using namespace std;

class MenuAdmin
{

public:
	int execute();
	void parentRecords();
	void classRecords();
	void studentReport();
};