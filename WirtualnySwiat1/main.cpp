#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Animal.h"
#include "Antelope.h"
#include "Belladona.h"
#include "CyberSheep.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Human.h"
#include "Organism.h"
#include "Plant.h"
#include "Point.h"
#include "Sheep.h"
#include "SosnowskyHogweed.h"
#include "SowThistle.h"
#include "Turtle.h"
#include "Wolf.h"
#include "World.h"
#include "WorldField.h"
#include <Windows.h>

int main()
{
	auto GameWorld = new World(20, 20);
	auto Owca = new Sheep(*GameWorld);
	auto Owca2 = new Sheep(*GameWorld);
	auto Owca3 = new Sheep(*GameWorld);
	auto Owca4 = new Sheep(*GameWorld);
	auto Zolw = new Turtle(*GameWorld);
	auto Zolw4 = new Turtle(*GameWorld);
	auto Zolw1 = new Turtle(*GameWorld);
	auto Zolw2 = new Turtle(*GameWorld);
	auto Wilk = new Wolf(*GameWorld);
	auto Wilk2 = new Wolf(*GameWorld);
	auto Wilk3 = new Wolf(*GameWorld);
	unsigned int Turn = 0;
	while (true)
	{
		std::cout << "Michal Krakowiak, 165596" << std::endl;
		std::cout << "Tura nr " << Turn << std::endl;
		Turn++;
		GameWorld->MakeTurn();
		GameWorld->Draw();
		Sleep(500);
		system("cls");
	}
	return 0;
}