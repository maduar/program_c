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

#endif
