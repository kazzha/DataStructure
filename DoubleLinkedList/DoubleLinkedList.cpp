#include "DoubleLinkedList.h"
#include <string>
#include <iostream>

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* element = new Monster;

	strcpy_s(element->name, NAME_LENGTH, name);
	element->hp = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = element;
	}
	else
	{
		element->pPrevious = list.pTail;
		list.pTail->pNext = element;
	}
	list.pTail = element;

	return nullptr;
}


int GetMonsterCount(const MonsterList& list)
{
	int count{};
	Monster* p = list.pHead;

	while (p)
	{
		count++;
		p = p->pNext;
	}
	return count;
}


void PrintMonsters(const MonsterList& list)
{
	Monster* p = list.pHead;

	while (p)
	{
		std::cout << "몬스터 : " << p->name << "  hp : " << p->hp << std::endl;
		p = p->pNext;
	}
}

void PrintMonstersR(Monster* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	Monster* p = pHead;

	std::cout << "몬스터 : " << p->name << "hp : " << p->hp << std::endl;
	PrintMonstersR(p->pNext);
}


Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;
	while (p)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p;
		}
		p = p->pNext;
	}
	return nullptr;
}


void DeleteAll(MonsterList& list)
{
	Monster* p = list.pHead;
	Monster* pNextInfo{};
	while (p)
	{
	    pNextInfo = p->pNext;
		delete p;

		p = pNextInfo;
	}

	list.pHead = nullptr;
	list.pTail = nullptr;

}


bool DeleteMonster(MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	while (p)
	{
		if (strcmp(p->name, name) == 0)
		{
			break;
		}

		p = p->pNext;

	}

	if (!p)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		list.pHead = nullptr;
		list.pTail = nullptr;
		
	}
	else if (p->pPrevious == nullptr)
	{
		list.pHead = p->pNext;
		
	}
	else if (p->pNext == nullptr)
	{
		list.pTail = p->pPrevious;
		
	}
	else
	{
		p->pPrevious->pNext = p->pNext;
		p->pNext->pPrevious = p->pPrevious;
	}

	delete p;
	return true;
}
