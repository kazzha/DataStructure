#include "DQueue.h"
#include <iostream>

void Push(QueueList& list, int container)
{
	Queue* element = new Queue;
	element->container = container;

	if (list.pTail == nullptr)
	{
		list.pHead = element;
	}
	else
	{
		list.pTail->pNext = element;
	}
	list.pTail = element;
}

void Pop(QueueList& list)
{
	Queue* p = list.pHead;
	if (p == nullptr)
	{
		std::cout << "Queue is already empty!!" << std::endl;
		return;
    }
	else if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
		std::cout << "Queue is empty" << std::endl;
		delete p;
	}
	else
	{
		list.pHead = list.pHead->pNext;
		delete p;
	}

}

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl
		      << "[1] PUSH" << std::endl
		      << "[2] POP" << std::endl
		      << "[3] QUIT" << std::endl
		      << "--------" << std::endl;
}

void PrintQueueR(Queue* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	Queue* p = pHead;

	std::cout << p->container << " ";

	PrintQueueR(p->pNext);
}