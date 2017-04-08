#include "World.h"
#include <iostream>


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
}


World::~World()
{
	for (int i = 0; i < Width; i++)
		delete Map[i];
	delete Map;
	delete Organisms;
}

int World::Draw()
{
	for (int i = 0; i < Height * Width; i++)
	{
		if ((*Organisms)[i] == nullptr)
			break;
		else if (!((*Organisms)[i]->IsDead()))
			(*Organisms)[i]->Draw();
	}

	for (int x = 0; x < this->Width; x++)
	{
		for (int y = 0; y < this->Height; y++)
		{
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
