#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h"

Status InitList_L(LinkList *L)
{
    (*L) = (LinkList)malloc( sizeof(LNode) );
    if ( !(*L) )
        exit(OVERFLOW);

    (*L) -> next = NULL;

    return OK;
}

Status ClearList_L(LinkList L)
{
    LinkList pre, p;
    if(!L)
        return ERROR;

    pre = L -> next;

    while(pre)
    {
        p = pre -> next;
        free(pre);
        pre = p;
    }

    L -> next = NULL;

    return OK;
}

void DestroyList_L(LinkList *L)
{
    LinkList p = *L;

    while(p)
    {
        p = (*L) -> next;
        free(*L);
        (*L) = p;
    }

}


Status ListEmpty_L(LinkList L)
{
    if( L != NULL && L -> next == NULL)
        return TRUE;
    else
        return FALSE;
}

int ListLength_L(LinkList L)
{
    LinkList p;
    int i;

    if(L)
    {
        i = 0;
        p = L -> next;
        while(p)
        {
            i++;
            p = p -> next;
        }
    }

    return i;
}

Status getElem_L(LinkList L, int i, LElemType_L *e){
    int j;
    LinkList p = L -> next;

    j = 1;
    p = L -> next;

    while(p && j < 1) {
        j++;
        p = p -> next;
    }

    if(!p || j > i)
        return ERROR;

    *e = p -> data;

    return OK;

}


Status ListInert_L(LinkList L, int i, LElemType_L e) {
    LinkList p, s;
    int j;

    p = L;
    j = 0;

    while(p && j < i - 1) {
        p = p -> next;
        ++j;
    }

    if(!p || j > i - 1)
        return ERROR;

    s = (LinkList)malloc(sizeof(LNode));
    if(!s)
        exit(OVERFLOW);

    s -> data = e;
    s -> next = p -> next;
    p -> next = s;

    return OK;
}

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)) {
    int i;
    LinkList p;

    i = -1;

    if(L) {
        i = 0;
        p = L -> next;

        while(p) {
            i++;

            if(!Compare(e, p -> data))
                p = p -> next;
            else
                break;
        }
    }

    return i;
}

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e) {
    LinkList p, suc;

    if(L) {

        p = L -> next;

        if(p -> data != cur_e) {
            while(p -> next) {
                suc = p -> next;
                if(suc -> data == cur_e) {
                    *pre_e = p -> data;
                    return OK;
                }

                p = suc;
            }
        }
    }

    return ERROR;
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e) {
    LinkList p, suc;
    if(L) {
        p = L -> next;

        while(p && p -> next) {
            suc = p -> next;
            if(suc && p -> data == cur_e) {
                *next_e = suc -> data;
                return OK;
            }

            if(suc)
                p = suc;
            else
                break;
        }
    }

}

Status ListDelete_L(LinkList L, int i, LElemType_L *e) {
    LinkList pre, p;
    int j;

    pre = L;
    j = 1;

    while(pre -> next && j < i) {
        pre = pre -> next;
        ++j;
    }

    if(!pre -> next || j > i)
        return ERROR;

    p = pre -> next;
    pre -> next = p -> next;
    *e = p -> data;
    free(p);

    return OK;

}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)) {
    LinkList p;

    if(!L)
        return ERROR;

    else
        p = L -> next;

    while(p) {
        Visit(p -> data);
        p = p -> next;
    }

    return OK;
}

Status CreateList_HL(FILE *fp, LinkList *L, int n) {
    int i;
    LinkList p;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L) -> next = NULL;

    for(i = 1; i <= n; ++i) {
        if(Scanf(fp, "%d", &tmp) == 1) {
            p = (LinkList)malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);

            p -> data = tmp;
            p -> next = (*L) -> next;
            (*L) -> next = p;
        } else
            return ERROR;
    }

    return OK;
}

Status CreateList_TL(FILE *fp, LinkList *L, int n) {
    int i;
    LinkList p, q;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L) -> next = NULL;

    for(i = 1, q = *L; i<= n; ++i) {
        if(Scanf(fp, "%d", &tmp) == 1) {
            p = (LinkList)malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p -> data = tmp;
            q -> next = p;
            q = q -> next;
        } else
            return ERROR;
    }

    q -> next = NULL;

    return OK;
}

#endif
