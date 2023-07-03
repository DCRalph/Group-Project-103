#pragma once

#include <iostream>
#include <optional>
#include <iomanip> 

#include "cliTools.h"
#include "db.h"

class MenuAdmin
{

public:
	int execute();
	void parentRecords();
	void classRecords();
	void studentReport();
};