#include <iostream>
#include "DQueue.h"

enum Command
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};

int main()
{
	PrintInfo();

	int num{};
	QueueList myList;


	while (true)
	{
		std::cout << " > ";
		std::cin >> num;
		switch (num)
		{
		case PUSH:
		{
			int value{};
			std::cout << "값을 입력하세요 > ";
			std::cin >> value;
			std::cout << std::endl;
			Push(myList, value);
			break;
		}
		case POP:
			Pop(myList);
			break;

		case QUIT:
			return 0;
			break;

		default:
			break;
		}
		PrintQueueR(myList.pHead);
		std::cout << std::endl;
	}
}