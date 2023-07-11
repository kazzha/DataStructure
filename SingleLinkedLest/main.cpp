#include <iostream>
#include "SingleLinkedList.h"

int main()
{
	MonsterList myList;

	CreateMonster(myList, "Demon", 100);
	CreateMonster(myList, "Wolf", 50);
	CreateMonster(myList, "Slime", 10);

	PrintMonstersDQ(myList.pHead);

	DeleteAll(myList);
	PrintMonsters(myList);
}