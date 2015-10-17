#include"stdio.h"
#include"stdlib.h"
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


char smallest_character(char str[], char c)
{
    int i = 0;
    while(str[i] != '~') {
        if(str[i]>c) {
            c = str[i];
            break;
        } else if(str[i] == '~') {
            c = str[0];
        } else
            i++;
    }
    return c;
}

int main()
{
    struct timespec start, end;
    FILE *fp;
    char str[100] = {'~'}, c;
    int n = 0;

    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("input error\n");
        return -1;
    }
    printf("The input array and character(last one) is: ");
    while(fscanf(fp, "%c ", &str[n]) != EOF) {
        printf("%c, ",str[n]);
        n++;
    }
    printf("\n");
    c = str[n-1];
    str[n-1] = '~';
    clock_gettime(CLOCK_REALTIME, &start);
    c = smallest_character(str,c);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Output: %c\n", c);
    printf("execution time: %lf nsec\n", diff_in_nsecond(start,end));
    fclose(fp);
    return 0;
}

