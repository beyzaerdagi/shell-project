#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size sizeof(content) / sizeof(char *)

int main(int argc, char *argv[]) {

    size_t n = 10;
    char *buf = malloc(sizeof(char) * n);
    printf("Enter input: ");
    getline(&buf, &n, stdin);

    char snum[10];
    char snum2[10];
    sprintf(snum, "%d", getpid());
    sprintf(snum2, "%d", getppid());
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    FILE *fptr;
    char ch;
    char *concatChar[100];
    char *content[6];
    content[0] = "System time:";
    content[1] = asctime (timeinfo);
    content[2] = "Pid:";
    content[3] = snum;
    content[4] = " PPid:";
    content[5] = snum2;

    for (int i = 0; i < size ;i++){
        strcat(concatChar, content[i]);
    }
    strcat(concatChar, "\n");

    fptr = fopen(argv[argc - 1], "a");

    if (fptr != NULL) {
        fprintf(fptr, "%s\n", buf);
        fprintf(fptr, "%s\n", concatChar);
        fclose(fptr);
    }else{
        fprintf(fptr, "%s\n", buf);
        fprintf(fptr, "%s\n", concatChar);
        fclose(fptr);
    }

    fptr = fopen(argv[argc - 1], "r");
   
    while ((ch = fgetc(fptr) )!= EOF) {
        printf ("%c", ch);
    }
    fclose(fptr);
    free(concatChar);
    free(content);
    return 0;
}
