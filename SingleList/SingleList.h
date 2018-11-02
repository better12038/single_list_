#pragma once

#include <stdio.h>
#include <windows.h>
#include <assert.h>

//����ʵ������Ĳ�������
// ֵ���� 
typedef int DataType;

typedef struct SListNode {
	DataType data; // ֵ 
	struct SListNode *pNext; // ָ����һ����� 
} SListNode;

// ��ʼ�� 
void SListInit(SListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//����
static SListNode* SListCreate(DataType data)
{
	SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}


// ͷ������ 
void SListPushFront(SListNode **ppFirst, DataType data)
{
	//ע��ָ�������
	SListNode *newNode = SListCreate(data);
	newNode->pNext = *ppFirst;
	*ppFirst = newNode;
}

//β��
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

// β��ɾ�� 
//���ҵ������ڶ���
void SListPopBack(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);
	//-----------������������ֻ��һ���ڵ�
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

// ͷ��ɾ�� 
void SListPopFront(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);  //����Ϊ������
	SListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->pNext;
	free(del);
}

// ���������룬���뵽���ǰ 
//pPos��ѡ�������ͷ/��β/�м䣩
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

// �������ɾ�� 
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

//// ��ֵɾ����ֻɾ�����ĵ�һ�� 
//void SListRemove(SListNode **ppFirst, DataType data)

//// ��ֵɾ����ɾ�����е� 
//void SListRemoveAll(SListNode **ppFirst, DataType data)

// ���� 
void SListDestroy(SListNode **ppFirst)
{
	*ppFirst = NULL;
}

// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
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


