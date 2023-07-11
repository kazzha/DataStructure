#pragma once

struct Queue
{
	int container{};

	Queue* pNext{};
};

struct QueueList
{
	Queue* pHead{};
	Queue* pTail{};
};

void Push(QueueList& list, int container);

void Pop(QueueList& list);

void PrintInfo();

void PrintQueueR(Queue* pHead);