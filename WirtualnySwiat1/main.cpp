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
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

int main()
{
	auto GameWorld = new World(52, 23);
	{
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
		auto Guarana0 = new Guarana(*GameWorld);
		auto Guarana1 = new Guarana(*GameWorld);
		auto Guarana2 = new Guarana(*GameWorld);
	}
	auto Czlowiek = new Human(*GameWorld);

	Direction PlayerMoveDirection;
	unsigned char c;
	bool ok = false;
	while (!Czlowiek->IsDead())
	{
		system("cls");
		std::cout << "Michal Krakowiak, 165596" << std::endl;
		std::cout << "Strzalki - poruszanie, s - zapisz, l - wczytaj, q - super moc" << std::endl;
		std::cout << "Aktualna sila czlowieka: " << Czlowiek->GetStrength() << std::endl;
		std::cout << "Tur do ponownego uzycia spuermocy: " << Czlowiek->GetSuperPowerOverload() << ", pozostalo tur: " << Czlowiek->GetSuperPowerTurnsLeft() << std::endl;
		GameWorld->Draw();
		do
		{
			c = getch();
			if (c == 224 || c == 0)
			{
				c = getch();
				switch (c)
				{
				case KEY_UP:
					PlayerMoveDirection = UP; break;
				case KEY_LEFT:
					PlayerMoveDirection = LEFT; break;
				case KEY_RIGHT:
					PlayerMoveDirection = RIGHT; break;
				case KEY_DOWN:
					PlayerMoveDirection = DOWN; break;
				default:
					PlayerMoveDirection = NONE;
				}
				ok = Czlowiek->Control(PlayerMoveDirection);
			}
			switch (c)
			{
				case 'q':
				case 'Q':
					ok = Czlowiek->SuperPower(); break;
				case 's':
				case 'S':
					break;
				case 'l':
				case 'L':
					break;
				case ESC:
					std::cout << "Gracz zakonczyl gre" << std::endl;
					GameWorld->AddLog("Gracz zakonczyl gre");
					system("pause");
					return 0;
				default:
					break;
			}
		} while (!ok);
		ok = false;
		GameWorld->MakeTurn();		
	}
	std::cout << "Gracz nie zyje, koniec gry :(" << std::endl;
	system("pause");
	GameWorld->AddLog("Gracz nie zyje, koniec gry :(");
	return 0;
}