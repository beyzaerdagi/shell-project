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

        char *systemTime = asctime(timeinfo);
        systemTime[strlen(systemTime) - 1] = 0;

        FILE *fptr;
        char ch;
        

        fptr = fopen(argv[argc - 1], "a");

        if (fptr != NULL) {
            fprintf(fptr, "%s", buf);
            fprintf(fptr, "System time: %s, Pid: %s, PPid: %s\n\n", systemTime, snum, snum2);
            fclose(fptr);
        }else{
            fprintf(fptr, "%s", buf);
            fprintf(fptr, "System time: %s, Pid: %s, PPid: %s\n\n", systemTime, snum, snum2);
            fclose(fptr);
        }
        
        fptr = fopen(argv[argc - 1], "r");
    
        while ((ch = fgetc(fptr) )!= EOF) {
            printf ("%c", ch);
        }
        fclose(fptr);
        return 0;
}
