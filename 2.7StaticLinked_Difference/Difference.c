#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"

void difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
    int i, j;
    int r, p, k;
    LElemType_S b;

    InitSpace_SL();
    *S = Malloc_SL();
    r = *S;     // r指向s的尾指针
    SPACE[r].cur = 0;

    for(j = 0; j<len_A; j++)
    {
        j = Malloc_SL();
        SPACE[i].data = A[j];
        SPACE[r].cur = i;
        r = i;
    }

    SPACE[r].cur = 0;

    for(j = 0; j<len_B; j++)
    {
        b = B[j];
        p = *S;
        k = SPACE[*S].cur;

        while(k && SPACE[k].data != b)
        {
            p = k;
            k = SPACE[k].cur;
        }

        if(!k)
        {
            i = Malloc_SL();
            SPACE[i].data = b;
            SPACE[i].cur = SPACE[r].cur;
            SPACE[r].cur = i;
        } else {
            SPACE[p].cur = SPACE[k].cur;
            Free_SL(k);
            if(k == r)
                r = p;
        }

    }
}

#endif