#pragma once


struct Stack
{
	int container{};

	Stack* pNext{};
	Stack* pPrevious{};
};

struct StackList
{
	Stack* pHead{};
	Stack* pTail{};
};

void Push(StackList& list, int container);

void Pop(StackList& list);

void PrintInfo();

void PrintStackR(Stack* pHead);