#pragma once

//#include "config.h"
#include <string>

using namespace std;

struct Color
{

  Color();

  string Red;
  string Green;
  string Yellow;
  string Blue;
  string Magenta;
  string Cyan;

  string BrightRed;
  string BrightGreen;
  string BrightYellow;
  string BrightBlue;
  string BrightMagenta;
  string BrightCyan;

  string Reset;
  string Bold;

  string red(string x);

  string green(string x);

  string yellow(string x);

  string blue(string x);

  string magenta(string x);

  string cyan(string x);

  string brightRed(string x);

  string brightGreen(string x);

  string brightYellow(string x);

  string brightBlue(string x);

  string brightMagenta(string x);

  string brightCyan(string x);

  string bold(string x);
};

extern Color internalColor;

class GetInput
{
public:
  string getString(string _color = "", string _pre = "");

  double getNumber(string _color = "", string _pre = "");
};

class Utils
{
public:
  void clear();
  void waitForKeyPress();
};

// void Clear();
// void waitForKeyPress();



// namespace CLI
// {
//   extern Color colorTest;
// }