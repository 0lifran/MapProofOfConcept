#include <stdio.h>
#include <iostream>
#include "MapController.h"

using namespace std;

int main()
{
	Tile tiles[4][4] = {};
	MapController mapController = 
		*new MapController(
			4, 
			4, 
			nullptr, 
			nullptr, 
			26);
	cout << "Hello" << endl;
}