#include <stdio.h>
#include "../util/Status.h"
#include "Difference.c"

void PrintElem(LElemType_S e);

int main(int argc, char **argv)
{
    SLinkList S;
    FILE *fp;
    int len_A, len_B, i;
    LElemType_S A[100], B[100];

    len_A = 3;
    len_B = 5;

    fp = fopen("TestData.txt", "r");

    for(i = 0; i<len_A; i++)
        Scanf(fp, "%d", &A[i]);

    for(i = 0; i<len_B; i++)
        Scanf(fp, "%d", &B[i]);

    fclose(fp);

    printf("A  = ");
    for(i = 0; i<len_A; i++)
        PrintElem(A[i]);



    return 0;
}

void PrintElem(LElemType_S e)
{
    printf("%d ", e);
}