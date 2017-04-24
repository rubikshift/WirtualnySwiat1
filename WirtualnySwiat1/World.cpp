#include "World.h"
#include "Antelope.h"
#include "Belladona.h"
#include "CyberSheep.h"
#include "Fox.h"
#include "Grass.h"
#include "Guarana.h"
#include "Human.h"
#include "Sheep.h"
#include "SosnowskyHogweed.h"
#include "SowThistle.h"
#include "Turtle.h"
#include "Wolf.h"
#include <iostream>
#include <ctime>
#define SHOW_LOGS_ON
World::World()
{
}

World::World(int Width, int Height)
{
	this->Width = Width;
	this->Height= Height;
	this->Map = new WorldField*[Width];
	for (int i = 0; i < Width; i++)
		this->Map[i] = new WorldField[Height];
	this->Organisms = new OrganismQueue(Width, Height);
	this->Turn = 0;
#ifdef DEBUG
	out.open(std::to_string(time(NULL)) + "_logs.txt", std::ofstream::out);
	t = 0;
#endif // DEBUG
}


World::~World()
{
	for (int i = 0; i < Width; i++)
		delete[] Map[i];
	delete[] Map;
	delete Organisms;
#ifdef DEBUG
	out.close();
#endif // DEBUG
}

int World::MakeTurn()
{
#ifdef DEBUG
	auto x = time(NULL);
#endif // DEBUG
	this->Organisms->Sort();
	for (int i = 0; i < Organisms->GetCount(); i++)
		(*Organisms)[i]->AllowMakingTurn();

	for (int i = 0; i < Organisms->GetCount(); i++)
	{
		if (!((*Organisms)[i]->IsDead()) && (*Organisms)[i]->IsTurnAllowed())
		{
			(*Organisms)[i]->Act();
			(*Organisms)[i]->GetOlder();
		}
	}
	this->Turn++;
#ifdef DEBUG
	auto n = time(NULL);
	t = n - x;
#endif // DEBUG	
	return 0;
}

int World::Draw()
{
	std::cout << "Tura nr " << this->Turn << std::endl;
#ifdef DEBUG
	std::cout << "Czas tury: " << this->t <<" s" << std::endl;
#endif // DEBUG	

	for (int x = 0; x < Width; x++)
		for (int y = 0; y < Height; y++)
			this->Map[x][y] = EMPTY;

	for (int i = 0; i < Organisms->GetCount(); i++)
	{
		if (!((*Organisms)[i]->IsDead()))
			(*Organisms)[i]->Draw();
	}

	for (int y = -1; y <= this->Height; y++)
	{
		for (int x = -1; x <= this->Width; x++)
		{
			if ((y == -1 || y == this->Height) && (x != -1 && x != this->Width))
				std::cout << (char)205;
			else if ((y != -1 && y != this->Height) && (x == -1 || x == this->Width))
				std::cout << (unsigned char)186;
			else if (y == -1 && x == -1)
				std::cout << (unsigned char)201;
			else if (y == -1 && x == this->Width)
				std::cout << (unsigned char)187;
			else if (y == this->Height && x == -1)
				std::cout << (unsigned char)200;
			else if (y == this->Height && x == this->Width)
				std::cout << (unsigned char)188;
			else
				std::cout << this->ParseWorldField(Map[x][y]);
				
		}
		std::cout << std::endl;
	}

	while (!this->Logs.empty())
	{
#ifdef SHOW_LOGS_ON
		std::cout << this->Logs.front() << std::endl;
#endif
		this->Logs.pop_front();
	}
	return 0;
}

WorldField ** World::GetMap()
{
	return this->Map;
}

void World::AddOrganismToWorld(Organism * LivingOrganism)
{
	this->Organisms->Add(LivingOrganism);
}

int World::GetWidth() const
{
	return this->Width;
}

int World::GetHeight() const
{
	return this->Height;
}

OrganismQueue * World::GetOrganismQueue()
{
	return this->Organisms;
}

bool World::IsEmptyNear(Point P)
{
	if (P.GetX() + 1 < this->Width && this->Organisms->Find({ P.GetX() + 1, P.GetY() }) == nullptr)
		return true;
	else if (P.GetX() - 1 >= 0 && this->Organisms->Find({ P.GetX() - 1, P.GetY() }) == nullptr)
		return true;
	else if (P.GetY() + 1 < this->Height && this->Organisms->Find({ P.GetX(), P.GetY() + 1 }) == nullptr)
		return true;
	else if (P.GetY() - 1 >= 0 && this->Organisms->Find({ P.GetX(), P.GetY() - 1 }) == nullptr)
		return true;
	return false;
}

void World::AddLog(std::string Log)
{
	Logs.push_back(Log);

#ifdef DEBUG
	time_t rawTime;
	time(&rawTime);
	auto ptm = gmtime(&rawTime);
	out << "Tura: " << this->Turn << ", "<< (ptm->tm_hour+2)%24 << ":" << ptm->tm_min << ":" << ptm->tm_sec << ", " << Log << std::endl;
#endif // DEBUG
}

void World::Save()
{
	std::fstream sav("Zapis.txt", std::ofstream::out);
	sav << this->Width << " " << this->Height << " " << this->Turn << " " << this->Organisms->GetCount() - this->Organisms->GetDeadCount() <<std::endl;
	for (int i = 0; i < this->Organisms->GetCount(); i++)
		if ((*Organisms)[i] != nullptr && !(*Organisms)[i]->IsDead())
			(*Organisms)[i]->Save(sav);
	sav.close();
}

Organism* World::Load()
{
	delete Organisms;
	for (int i = 0; i < Width; i++)
		delete[] Map[i];
	delete[] Map;
	int Species, count;
	Organism* tmp;
	Organism* czlowiek;
	std::fstream sav("Zapis.txt", std::ifstream::in);
	sav >> this->Width >> this->Height >> this->Turn >> count;
	this->Map = new WorldField*[Width];
	for (int i = 0; i < Width; i++)
		this->Map[i] = new WorldField[Height];
	this->Organisms = new OrganismQueue(Width, Height);
	for(int i =0; i < count; i++)
	{
		sav >> Species;
		switch ((WorldField)Species)
		{
			case ANTELOPE: 
				tmp = new Antelope(*this, sav); break;
			case BELLADONA: 
				tmp = new Belladona(*this, sav); break;
			/*case CYBER_SHEEP: 
				tmp = new CyberSheep(*this, sav); break;*/
			case FOX:
				tmp = new Fox(*this, sav); break;
			case GRASS:
				tmp = new Grass(*this, sav); break;
			case GUARANA:
				tmp = new Guarana(*this, sav); break;
			case HUMAN:
				czlowiek = new Human(*this, sav); break;
			case SHEEP:
				tmp = new Sheep(*this, sav); break;
			case SOSNOWSKY_HOGWEED:
				tmp = new SosnowskyHogweed(*this, sav); break;
			case SOW_THISTLE:
				tmp = new SowThistle(*this, sav); break;
			case TURTLE:
				tmp = new Turtle(*this, sav); break;
			case WOLF:
				tmp = new Wolf(*this, sav); break;
		}
		
	}
	sav.close();
	return czlowiek;
}

char World::ParseWorldField(WorldField Field)
{
	switch (Field)
	{
	case ANTELOPE:
		return 'A';
	case BELLADONA:
		return 'J';
	case CYBER_SHEEP:
		return 'C';
	case FOX:
		return 'L';
	case GRASS:
		return 'T';
	case GUARANA:
		return 'G';
	case HUMAN:
		return 'H';
	case SHEEP:
		return 'O';
	case SOSNOWSKY_HOGWEED:
		return 'B';
	case SOW_THISTLE:
		return 'M';
	case TURTLE:
		return 'Z';
	case WOLF:
		return 'W';
	default:
		return ' ';
	}
}
