#include "OrganismQueue.h"
#include "Human.h"


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
	for (int i = 0; i < this->Count; i++)
		delete Organisms[i];
	delete[] Organisms;
}

void OrganismQueue::Add(Organism * LivingOrganism)
{
	if (this->FindDead() != -1)
	{
		int i = this->FindDead();
		delete this->Organisms[i];
		this->Organisms[i] = LivingOrganism;
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
	if (Count == 0 || Count >= Size)
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

int OrganismQueue::FindDead()
{
	for (int i = 0; i < Size; i++)
		if (Organisms[i] != nullptr && Organisms[i]->IsDead() && dynamic_cast<Human*>(Organisms[i]) == nullptr)
			return i;
	return -1;
}

Organism * OrganismQueue::Find(Point P)
{
	for (int i = 0; i < Size; i++)
		if (Organisms[i] != nullptr && !Organisms[i]->IsDead() && Organisms[i]->GetPosition() == P)
			return Organisms[i];
	return nullptr;
}

int OrganismQueue::GetCount() const
{
	return this->Count;
}
