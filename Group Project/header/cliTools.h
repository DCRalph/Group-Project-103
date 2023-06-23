#pragma once

#include <iostream>
#include <string>

#include "color.h"

using namespace std;

class GetInput
{
public:
  string getString(string _color = "", string _pre = "");
  double getNumber(string _color = "", string _pre = "");
  bool getYesNo(bool _default = false);
};

class Utils
{
public:
  void clear();
  void waitForKeyPress();
};

extern GetInput getInput;
extern Utils utils;