#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>
#include "../util/Status.h"

#define MAXSIZE 1000

typedef int SLinkList;
typedef int LElemType_S;

typedef struct {
    LElemType_S data;
    int cur;
}Component[MAXSIZE];

Component SPACE;

void InitSpace_SL();

int Malloc_SL();

void Free_SL();

int InitList_SL(SLinkList *H);

Status ClearList_SL(SLinkList H);

void DestroyList_SL(SLinkList *H);

Status ListEmpty_SL(SLinkList H);

int ListLength_SL(SLinkList H);

Status GetElem_SL(SLinkList H, int i, LElemType_S *e);

int LocateElem_SL(SLinkList H, LElemType_S e);

Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);

Status NextElem_SL(SLinkList h, LElemType_S cur_e, LElemType_S *next_e);

Status ListInsert_SL(SLinkList H, int i, LElemType_S e);

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e);

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));

#endif