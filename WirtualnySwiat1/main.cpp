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
	auto GameWorld = new World(50, 25);

	auto Owca0 = new Sheep(*GameWorld);
	auto Owca1 = new Sheep(*GameWorld);
	auto Owca2 = new Sheep(*GameWorld);
	auto Owca3 = new Sheep(*GameWorld);
	auto Zolw0 = new Turtle(*GameWorld);
	auto Zolw1 = new Turtle(*GameWorld);
	auto Zolw2 = new Turtle(*GameWorld);
	auto Zolw3 = new Turtle(*GameWorld);
	auto Antylopa0 = new Antelope(*GameWorld);
	auto Antylopa1 = new Antelope(*GameWorld);
	auto Antylopa2 = new Antelope(*GameWorld);
	auto Antylopa3 = new Antelope(*GameWorld);
	auto Lis0 = new Fox(*GameWorld);
	auto Lis1 = new Fox(*GameWorld);
	auto Lis2 = new Fox(*GameWorld);
	auto Lis3 = new Fox(*GameWorld);
	auto Wilk0 = new Wolf(*GameWorld);
	auto Wilk1 = new Wolf(*GameWorld);
	auto Wilk2 = new Wolf(*GameWorld);
	auto Trawa0 = new Grass(*GameWorld);
	auto Trawa1 = new Grass(*GameWorld);
	auto Mlecz0 = new SowThistle(*GameWorld);
	auto Mlecz1 = new SowThistle(*GameWorld);
	auto Mlecz2 = new SowThistle(*GameWorld);
	auto WilczaJagoda0 = new Belladona(*GameWorld);
	auto WilczaJagoda1 = new Belladona(*GameWorld);
	auto WilczaJagoda2 = new Belladona(*GameWorld);
	auto BarszczSosnowskiego0 = new SosnowskyHogweed(*GameWorld);
	auto BarszczSosnowskiego1 = new SosnowskyHogweed(*GameWorld);
	auto BarszczSosnowskiego2 = new SosnowskyHogweed(*GameWorld);


	while (true)
	{
		std::cout << "Michal Krakowiak, 165596" << std::endl;
		GameWorld->Draw();
		GameWorld->MakeTurn();
		Sleep(100);
		system("cls");
	}
	return 0;
}