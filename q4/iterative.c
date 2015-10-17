#include"stdio.h"

int maxSubArray(int A[], int n)
{
    int maxAll = 0, maxCurrent = 0;
    int i = 0;
    for(i=0; i<n; i++) {
        maxCurrent = maxCurrent + A[i];
        if(maxCurrent < 0)
            maxCurrent = 0;
        if(maxAll < maxCurrent)
            maxAll = maxCurrent;
    }
    return maxAll;
}

int main()
{
    FILE *fp;
    int A[100]= {0};
    int i = 0, n = 0;
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("input error\n");
        return -1;
    }
    while(fscanf(fp, "%d", &A[n]) != EOF)
        n++;
    printf("The input array is: ");
    for(i=0; i<n; i++)
        printf("%d, ",A[i]);
    printf("\n");
    printf("The largest sum is: %d\n",maxSubArray(A,n));
    fclose(fp);
    return 0;
}


