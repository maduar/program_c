#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include <stdio.h>
#include "StaticLinkedList.h"

void InitSpace_SL() {
    int i;

    for(i = 0; i < MAXSIZE -1 ; i++)
        SPACE[i].cur = i + 1;

    SPACE[MAXSIZE -1].cur = 0;
}

int Malloc_SL() {
    int i;

    i = SPACE[0].cur;

    if(SPACE[0].cur) {
        SPACE[0].cur = SPACE[i].cur;
        return i;
    } else
        return 0;

}

void Free_SL(int k){
    SPACE[k].cur = SPACE[0].cur;
    SPACE[0].cur = k;
}

Status InitList_SL(SLinkList *H) {
    *H = Malloc_SL();
    if(!(*H))
        exit(OVERFLOW);

    SPACE[*H].cur = 0;

    return OK;
}

Status ClearList_SL(SLinkList H) {
    int p, q;
    if(!(H))
        return ERROR;

    p = SPACE[H].cur;

    while(p) {
        SPACE[H].cur = SPACE[p].cur;
        Free_SL(p);
        p = SPACE[H].cur;
    }

    return OK;
}

void DestroyList(SLinkList *H) {
    ClearList_SL(*H);

    Free_SL(*H);
    *H = 0;
}

Status ListEmpty_SL(SLinkList H) {
    if(H && !SPACE[H].cur)
        return TRUE;
    else
        return FALSE;
}

int ListLength_SL(SLinkList H) {
    int count;
    int p;

    if(!H)
        exit(OVERFLOW);

    count = 0;
    p = SPACE[H].cur;

    while(p) {
        count++;
        p = SPACE[p].cur;
    }

    return count;
}



Status ListInsert_SL(SLinkList H, int i, LElemType_S e) {
    int count, k, p;

    if(!H) {
        count = 0;
        k = H;

        while(k && count < i -1 ) {
            count++;
            k = SPACE[k].cur;
        }

        if(k) {
            p = Malloc_SL();
            if(!p)
                return ERROR;

            SPACE[p].data = e;
            SPACE[p].cur = SPACE[k].cur;
            SPACE[k].cur = p;

            return OK;
        }

    }

    return ERROR;
}

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e) {
    int count, k, p;

    if(!H)
        return ERROR;

    if(i > 0) {
        count = 0;
        k = H;

        while(k && count < i -1) {
            count++;
            k = SPACE[k].cur;
        }

        if(k && SPACE[k].cur) {
            p = SPACE[k].cur;
            *e = SPACE[p].data;
            SPACE[k].cur = SPACE[p].cur;
            Free_SL(p);

            return OK;
        }

    }

    return ERROR;
}

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S)) {
    int p;

    if(!H)
        return ERROR;

    p = SPACE[H].cur;

    while(p) {
        Visit(SPACE[p].data);
        p = SPACE[p].cur;
    }

    return OK;
}

#endif
