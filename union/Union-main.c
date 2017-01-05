#include <stdio.h>
#include "Union.c"

void PrintElem(LElemType_Sq e);

int main(int argc, char **argv) {
    SqList La, Lb;
    LElemType_Sq a[5] = {1, 2, 4, 6, 7};
    LElemType_Sq b[6] = {4, 2, 3, 5, 9, 8};
    int i;

    InitList_Sq(&La);
    for(i = 1; i <= 5; i++)
        ListInsert_Sq(&La, i, a[i -1]);

    InitList_Sq(&Lb);
    for(i = 1; i <= 6; i++)
        ListInsert_Sq(&Lb, i, b[i -1]);

    printf("La = ");
    ListTraverse_Sq(La, PrintElem);
    printf("\n\n");

    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);

    printf("\n\n");
    int test = equal(1, 2);
    printf("test: %d\n", test);

    printf("\n\n");
    Union(&La, Lb);
    ListTraverse_Sq(La, PrintElem);
    printf("\n\n");

    return 0;

}

void PrintElem(LElemType_Sq e) {
    printf("%d ", e);
}