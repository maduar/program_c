#ifndef UNION_C
#define UNION_C

#include "Union.h"

void Union(SqList *La, SqList Lb) {
    int La_len, Lb_len;
    LElemType_Sq e;
    int i;

    La_len = ListLength_Sq(*La);
    Lb_len = ListLength_Sq(Lb);

    for(i = 1; i <= Lb_len; i++) {
        GetElem_Sq(Lb, i, &e);
        if(!LocateElem_Sq(*La, e, equal)) {
            ListInsert_Sq(La, ++La_len, e);
        }
    }
}

Status equal(LElemType_Sq e1, LElemType_Sq e2) {
    return e1 == e2 ? TRUE : FALSE;
}

#endif