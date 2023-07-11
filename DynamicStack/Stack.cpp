#include "Stack.h"
#include <iostream>

void Push(StackList& list, int container)
{
	Stack* element = new Stack;
	element->container = container;

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
}

void Pop(StackList& list)
{
	Stack* p = list.pTail;

	if (list.pTail == nullptr)
	{
		std::cout << "Stack is already empty!" << std::endl;
		return;
	}
	else if (list.pTail == list.pHead)
	{
		list.pHead = list.pTail = nullptr;
		delete p;
		std::cout << "Stack is empty" << std::endl;
	}
	else
	{
		list.pTail = p->pPrevious;
		list.pTail->pNext = nullptr;
		delete p;
	}
}

void PrintInfo()
{
	std::cout << "<STACK>" << std::endl
	          << "[1] push" << std::endl
	          << "[2] pop" << std::endl
	          << "[3] quit" << std::endl
	          << "--------" << std::endl;
}

void PrintStackR(Stack* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	Stack* p = pHead;

	PrintStackR(p->pNext);

	std::cout << p->container << std::endl;
}
