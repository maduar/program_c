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

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L a, LElemType_L b));
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next);

Status ListDelete_L(LinkList L, int i, LElemType_L *e);

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));

Status CreateList_HL(FILE *fp, LinkList *L, int n);
Status CreateList_TL(FILE *fp, LinkList *L, int n);

Status getElem_L(LinkList L, int i, LElemType_L *e);
Status ListInert_L(LinkList L, int i, LElemType_L e);

#endif