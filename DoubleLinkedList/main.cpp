#include "DoubleLinkedList.h"
#include <iostream>


int main()
{
	MonsterList myList;

	CreateMonster(myList, "Demon", 100);
	CreateMonster(myList, "Wolf", 50);
	CreateMonster(myList, "Slime", 10);

	
	std::cout << GetMonsterCount(myList) << "¸¶¸®" << std::endl;
	

	std::cout << FindMonster(myList, "Demon")->name;

	DeleteMonster(myList, "Demon");

	PrintMonstersR(myList.pHead);

	DeleteAll(myList);


	PrintMonstersR(myList.pHead);
}