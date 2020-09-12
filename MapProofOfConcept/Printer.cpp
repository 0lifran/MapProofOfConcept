#include "Printer.h"
#include <iostream>

using namespace std;


void Printer::print(string input, TerminalColor colorId)
{
	cout << this->formatString(input, colorId);
}

string Printer::formatString(string input, TerminalColor colorId)
{
	return "\x1B[" + to_string((int)colorId) + "m" + input + "\033[0m";
}