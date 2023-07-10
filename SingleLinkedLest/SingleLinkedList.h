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
void DeleteAll(MonsterList& list); // const 쓰지 않는 이유: 리스트가 바뀔것이기 때문

// Delete Element & bool 쓰는이유: 지웠는지 안 지웠는지 알기 편하게 활용도가 높음. void를 써도 되긴 함
bool DeleteMonster(MonsterList& list, const char* name); 
