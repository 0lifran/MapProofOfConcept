#include "pch.h"
#include "CppUnitTest.h"
#include "../MapProofOfConcept/MapController.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(TestClassInit)
		{
			Tile** tiles = new Tile * [16, 16]();
			for (int x = 0; x < 16; x++)
			{
				for (int y = 0; y < 16; y++)
				{
					tiles[x][y] = *new Tile (TileType::Grass);
				}
			}

			Unit* dummy1 = new Unit(1,1,"Dummy1","Dummy.png");
			Unit* dummy2 = new Unit(1,2,"Dummy2","Dummy.png");

			tiles[0][0] = *new Tile(TileType::Grass, 2);
			tiles[0][0].AddUnit(0,0,dummy2);

			tiles[1][0] = *new Tile(TileType::Grass, 2);
			tiles[2][0] = *new Tile(TileType::Grass, 2);
			tiles[0][1] = *new Tile(TileType::Grass, 2);
			tiles[0][2] = *new Tile(TileType::Grass, 2);
			tiles[0][3] = *new Tile(TileType::Grass, 2);

			MapController* mapController = new MapController(128, 128, tiles);
			mapController->AddUnit(dummy1);
		}
	};
}