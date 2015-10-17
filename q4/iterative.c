#include"stdio.h"
#include <time.h>

static double diff_in_nsecond(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec*1000000000.0 + diff.tv_nsec );
}

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
    struct timespec start, end;
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
    clock_gettime(CLOCK_REALTIME, &start);
    printf("The largest sum is: %d\n",maxSubArray(A,n));
    clock_gettime(CLOCK_REALTIME, &end);
    printf("execution time: %lf nsec\n", diff_in_nsecond(start,end));
    fclose(fp);
    return 0;
}


