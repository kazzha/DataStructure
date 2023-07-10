#pragma once

#include "Monster.h"

struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

// Create
Monster* CreateMonster(MonsterList& list, const char* name, const int hp);

// Count
int GetMonsterCount(const MonsterList& list);

// Print
void PrintMonsters(const MonsterList& list);
void PrintMonstersDQ(Monster* pHead);

// Search
Monster* FindMonster(const MonsterList& list, const char* name);

// Delete All
void DeleteAll(MonsterList& list); // const ���� �ʴ� ����: ����Ʈ�� �ٲ���̱� ����

// Delete Element & bool ��������: �������� �� �������� �˱� ���ϰ� Ȱ�뵵�� ����. void�� �ᵵ �Ǳ� ��
bool DeleteMonster(MonsterList& list, const char* name); 
