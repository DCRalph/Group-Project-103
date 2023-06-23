#pragma once

#include <iostream>

#include "cliTools.h"
#include "db.h"

using namespace std;

class MenuParent
{

public:
	int execute();
	void childRecord();
	void schoolNotice();
};