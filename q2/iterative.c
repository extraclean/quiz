#include"stdio.h"
#include"stdlib.h"

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
    c = smallest_character(str,c);
    printf("Output: %c\n", c);
    fclose(fp);
    return 0;
}

