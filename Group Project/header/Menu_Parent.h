#pragma once

#include <iostream>
#include <optional>

#include "cliTools.h"
#include "db.h"

class MenuParent
{

public:
	int execute();
	void childRecord();
	void schoolNotice();
};