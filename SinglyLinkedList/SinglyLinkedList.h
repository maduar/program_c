#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../util/Status.h"
#include "../util/Scanf.c"

typedef int LElemType_L;

typedef struct LNode
{
    LElemType_L data;
    struct LNode* next;
}LNode;

typedef LNode* LinkList;
//#endif

Status InitList_L(LinkList *L);

Status ClearList_L(LinkList L);

void DestroyList_L(LinkList *L);

Status ListEmpty_L(LinkList L);

int ListLength_L(LinkList L);

#endif