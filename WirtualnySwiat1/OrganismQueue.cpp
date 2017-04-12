#include "OrganismQueue.h"



OrganismQueue::OrganismQueue(int m, int n)
{
	this->Size = m*n;
	this->Organisms = new Organism*[this->Size];
	for (int i = 0; i < this->Size; i++)
		this->Organisms[i] = nullptr;
	this->Count = 0;
}


OrganismQueue::~OrganismQueue()
{
	delete[] Organisms;
}

void OrganismQueue::Add(Organism * LivingOrganism)
{
	if (Count >= Size)
	{
		Organism* tmp = this->FindDead();
		if(tmp == nullptr)
			return;
		delete tmp;
		tmp = LivingOrganism;
	}
	else
	{
		this->Organisms[Count] = LivingOrganism;
		Count++;
	}
}

Organism * OrganismQueue::operator[](int i)
{
	if (i >= Count)
		return nullptr;
	else
		return Organisms[i];
}

void OrganismQueue::Sort()
{
	if (Count == 0)
		return;
	Organism* temp;
	for (int i = 0; i < Count; i++)
		for (int q = 0; q < Count - 1; q++)
		{
			if ((Organisms[q]->GetInitative() < Organisms[q + 1]->GetInitative())
				|| (Organisms[q]->GetInitative() == Organisms[q + 1]->GetInitative() 
					&& Organisms[q]->GetAge() < Organisms[q + 1]->GetAge()))
			{
				temp = Organisms[q];
				Organisms[q] = Organisms[q + 1];
				Organisms[q + 1] = temp;
			}
			
		}
}

Organism * OrganismQueue::FindDead()
{
	for (int i = 0; i < Size; i++)
		if (Organisms[i]->IsDead())
			return Organisms[i];
	return nullptr;
}

Organism * OrganismQueue::Find(Point P)
{
	for (int i = 0; i < Size; i++)
		if (Organisms[i]->GetPosition() == P)
			return Organisms[i];
	return nullptr;
}