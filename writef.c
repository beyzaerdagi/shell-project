#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *fptr;
    char ch;
    size_t n = 10;
    char *buf = malloc(sizeof(char) * n);
    printf("Enter input: ");
    getline(&buf, &n, stdin);

    char pid[10];
    char ppid[10];
    // Converts pid values ​​to string
    sprintf(pid, "%d", getpid());
    sprintf(ppid, "%d", getppid());

    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    //Deletes the \n at the end of system time
    char *systemTime = asctime(timeinfo);
    systemTime[strlen(systemTime) - 1] = 0;

    //Opens the file as appended to the end
    fptr = fopen(argv[argc - 1], "a");

    if (fptr != NULL) {
        // If the file does not exist, it creates the file and writes it to the file with the fprintf function
        fprintf(fptr, "%s", buf);
        fprintf(fptr, "System time: %s, Pid: %s, PPid: %s\n\n", systemTime, pid, ppid);
        fclose(fptr);
    }else{
        // If the file exists, append it to the end of the file
        fprintf(fptr, "%s", buf);
        fprintf(fptr, "System time: %s, Pid: %s, PPid: %s\n\n", systemTime, pid, ppid);
        fclose(fptr);
    }
    // Opens the file in read mode
    fptr = fopen(argv[argc - 1], "r");
    
    // Prints the file content until it runs out
    while ((ch = fgetc(fptr) )!= EOF) {
        printf ("%c", ch);
    }
    // Close file
    fclose(fptr);
    return 0;
}
