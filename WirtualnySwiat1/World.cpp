#include "World.h"
#include <iostream>

#include <ctime>

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
#endif // DEBUG
}


World::~World()
{
	for (int i = 0; i < Width; i++)
		delete Map[i];
	delete Map;
	delete Organisms;
#ifdef DEBUG
	out.close();
#endif // DEBUG
}

int World::MakeTurn()
{
	for (int i = 0; i < Organisms->GetCount(); i++)
	{
		if (!((*Organisms)[i]->IsDead()))
		{
			(*Organisms)[i]->Act();
			(*Organisms)[i]->GetOlder();
		}
	}
	this->Turn++;
	return 0;
}

int World::Draw()
{
	std::cout << "Tura nr " << this->Turn << std::endl;

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
			if ((y == -1 || y == this->Height) || (x == -1 || x == this->Width))
			{
				std::cout << "#";
				continue;
			}
			switch (Map[x][y])
			{
				case EMPTY:
					std::cout << " ";
					break;
				case ANTELOPE:
					std::cout << "A";
					break;
				case BELLADONA:
					std::cout << "J";
					break;
				case CYBER_SHEEP:
					std::cout << "C";
					break;
				case FOX:
					std::cout << "L";
					break;
				case GRASS:
					std::cout << "T";
					break;
				case GUARANA:
					std::cout << "G";
					break;
				case HUMAN:
					std::cout << "P";
					break;
				case SHEEP:
					std::cout << "O";
					break;
				case SOSNOWSKY_HOGWEED:
					std::cout << "B";
					break;
				case SOW_THISTLE:
					std::cout << "M";
					break;
				case TURTLE:
					std::cout << "Z";
					break;
				case WOLF:
					std::cout << "W";
					break;
				default:
					std::cout << " ";
					break;
			}
		}
		std::cout << std::endl;
	}

	while (!this->Logs.empty())
	{
		std::cout << this->Logs.front() << std::endl;
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
	this->Organisms->Sort();
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
