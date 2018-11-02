#pragma once

#include <stdio.h>
#include <windows.h>
#include <assert.h>

//代码实现链表的操作函数
// 值类型 
typedef int DataType;

typedef struct SListNode {
	DataType data; // 值 
	struct SListNode *pNext; // 指向下一个结点 
} SListNode;

// 初始化 
void SListInit(SListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//创建
static SListNode* SListCreate(DataType data)
{
	SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}


// 头部插入 
void SListPushFront(SListNode **ppFirst, DataType data)
{
	//注意指针的问题
	SListNode *newNode = SListCreate(data);
	newNode->pNext = *ppFirst;
	*ppFirst = newNode;
}

//尾插
void SListPushBack(SListNode **ppFirst, DataType data)
{
	SListNode *newNode = SListCreate(data);
	SListNode *cur = *ppFirst;
	if (*ppFirst == NULL)
	{
		*ppFirst = newNode;
		return;
	}
	while (cur->pNext != NULL)
	{
		cur = cur->pNext;
	}
	cur->pNext = newNode;
}

// 尾部删除 
//得找到倒数第二个
void SListPopBack(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);
	//-----------特例：链表中只有一个节点
	if ((*ppFirst)->pNext == NULL)
	{
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	//-------------
	SListNode *cur = *ppFirst;
	while (cur->pNext->pNext != NULL)
	{
		cur = cur->pNext;
	}
	free(cur->pNext);
	cur->pNext = NULL;
}

// 头部删除 
void SListPopFront(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);  //不能为空链表
	SListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->pNext;
	free(del);
}

// 给定结点插入，插入到结点前 
//pPos的选择可能是头/（尾/中间）
void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data)
{
	if (*ppFirst == pPos)
	{
		SListPushFront(ppFirst, data);
		return;
	}
	SListNode *cur = *ppFirst;
	while (cur->pNext != pPos)
	{
		cur = cur->pNext;
	}
	SListNode * newNode = SListCreate(data);
	newNode->pNext = cur->pNext;
	cur->pNext = newNode;
}

// 给定结点删除 
void SListErase(SListNode **ppFirst, SListNode *pPos)
{
	if (*ppFirst = pPos)
	{
		SListPopFront(ppFirst);
		return;
	}
	SListNode *cur = *ppFirst;
	while (cur->pNext != pPos)
	{
		cur = cur->pNext;
	}
	cur->pNext = pPos->pNext;
	free(pPos);
}

//// 按值删除，只删遇到的第一个 
//void SListRemove(SListNode **ppFirst, DataType data)

//// 按值删除，删除所有的 
//void SListRemoveAll(SListNode **ppFirst, DataType data)

// 销毁 
void SListDestroy(SListNode **ppFirst)
{
	*ppFirst = NULL;
}

// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
SListNode * SListFind(SListNode *pFirst, DataType data)
{
	assert(pFirst);
	for (SListNode *cur = pFirst; cur != NULL; cur = cur->pNext)
	{
		if (cur->data == data)
		{
			//printf("%d\n", cur);
			return cur;
		}
	}
	return NULL;
}


void SListPrint(SListNode **ppFirst)
{
	SListNode *cur = *ppFirst;
	while (cur->pNext != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->pNext;
	}
	printf("%d\n", cur->data);
}

void test()
{
	SListNode* first;
	SListInit(&first);

	SListPushBack(&first, 1);
	SListPushBack(&first, 2);
	SListPushBack(&first, 3);
	SListPushBack(&first, 4);
	SListPushBack(&first, 5);

	SListPrint(&first);

	SListPopFront(&first);
	SListPrint(&first);

	SListPopBack(&first);
	SListPrint(&first);

	SListNode * result = SListFind(first, 3);

	SListInsert(&first, result, 8);
	SListPrint(&first);

	SListErase(&first, result);
	SListPrint(&first);


	//SListDestroy(&first);
}


