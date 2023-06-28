#pragma once

#include <iostream>

#include "cliTools.h"
#include "db.h"
// #include "color.h"

class MenuRegister
{

public:
  int execute();
  void registerTeacher(int _classRoomNumber = -1);
  void registerParent();
};