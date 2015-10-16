/* FIXME: Implement! */
#include"stdio.h"
#include"stdlib.h"

char smallest_character(char*, char);

int main()
{
    FILE *fp;
    char *str, c;

    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("input error\n");
        return -1;
    }
        fscanf(fp, "%c %c %c %c %c\n %c", &str[0], &str[1], &str[2], &str[3], &str[4], &c);
    c = smallest_character(str,c);
    printf("%c\n", c);
    fclose(fp);
    return 0;
}

char smallest_character(char str[], char c)
{
    int i = 0;
    while(str[i] != NULL) {
        if(str[i]>c) {
            c = str[i];
            break;
        } else
            i++;
    }
    if(str[i] == NULL) {
        c = str[0];
    }
    return c;
}
