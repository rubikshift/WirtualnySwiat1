#include <cstdlib>
#include <cstdio>
#include <conio.h>
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

int main()
{
	auto GameWorld = new World(20, 20);
	auto Owca = new Sheep(*GameWorld);
	auto Owca2 = new Sheep(*GameWorld);
	auto Wilk = new Wolf(*GameWorld);
	auto Wilk2 = new Wolf(*GameWorld);
	while (true)
	{
		GameWorld->MakeTurn();
		GameWorld->Draw();
		getch();
		system("cls");
	}
	return 0;
}