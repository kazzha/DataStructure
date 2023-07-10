#include "SingleLinkedList.h"
#include <string>
#include <iostream>

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* element = new Monster;  // delete �Լ��� �� ������ ���ƾ� ��
	 
	//for (char* p = name[0]; *p != '\0'; p++)
	strcpy_s(element->name, NAME_LENGTH, name); //microsoft���� strcpy�� ������ ����:strcpy_s
	element->hp = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = element;
	}
	else
	{
		list.pTail->pNext = element; // new�� element
	}
	list.pTail = element;

	return element;
}

int GetMonsterCount(const MonsterList& list)
{
	Monster* p = list.pHead;
	int count{};

	while (p != nullptr) // = while(p)
	{
		count++;
		p = p->pNext;
	}
	return count;
}

void PrintMonsters(const MonsterList& list)
{
	Monster* p = list.pHead;

	while (p != nullptr) 
	{
		std::cout << "���� : " << p->name << std::endl << "hp : " << p->hp << std::endl;
		p = p->pNext;
	}
}

void PrintMonstersDQ(Monster* pHead)
{
	if (pHead == nullptr)
	{
		return;
    }

	std::cout << "���� : " << pHead->name << std::endl << "hp : " << pHead->hp << std::endl;

	PrintMonstersDQ(pHead->pNext);
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

	Monster* pNext{};

	while( p != nullptr )
	{
		pNext = p->pNext;
		delete p;
		
		p = pNext;
	}

	list.pHead = list.pTail = nullptr; // ��۸� ����Ʈ ���ɼ��� �־ ������ ���� ��ġ
}

bool DeleteMonster(MonsterList& list, const char* name)
{
	return false;
}
