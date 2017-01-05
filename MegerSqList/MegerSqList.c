#ifndef MEGERSQLIST_C
#define MEGERSQLIST_C

#include "MegerSqList.h"

void MergerSqList_1(SqList La, SqList Lb, SqList *Lc) {
    int La_len, Lb_len;
    int i, j, k;
    LElemType_Sq ai, aj;

    i = j = 1;
    k = 0;

    InitList_Sq(Lc);
    La_len = ListLength_Sq(La);
    Lb_len = ListLength_Sq(Lb);

    while(i <= La_len && j <= Lb_len) {
        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &aj);

        if(ai <= aj) {
            ListInsert_Sq(Lc, ++k, ai);
            i++;
        } else {
            ListInsert_Sq(Lc, ++k, aj);
            j++;
        }
    }

    while(i <= La_len) {
        GetElem_Sq(La, i++, &ai);
        ListInsert_Sq(Lc, ++k, ai);
    }

    while(j <= Lb_len) {
        GetElem_Sq(Lb, j++, &aj);
        ListInsert_Sq(Lc, ++k, aj);
    }

}



#endif