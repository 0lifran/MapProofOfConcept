#include <string>
#include "TerminalColor.h"
#pragma once

using namespace std;
class Printer
{
public:
	void print(string input, TerminalColor colorId);
	string formatString(string input, TerminalColor colorId);
};

