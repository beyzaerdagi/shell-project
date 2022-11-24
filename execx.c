#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define clear() printf("\033[H\033[J") 

int main(int argc, char *argv[]) {

    int f, status;

    if (strcmp(argv[3], "clear") == 0){
        clear();
    }else if (strcmp(argv[3], "ls") == 0){
        for (int i = 0; i < atoi(argv[2]);i++){
            system("/bin/ls");
        }
    }else if (strcmp(argv[3], "cat") == 0){
        for (int i = 0; i < atoi(argv[2]);i++){
            printf("cat:%s\n", argv[4]);
        }
    }else if (strcmp(argv[3], "bash") == 0){
        for (int i = 0; i < atoi(argv[2]);i++){
            system("/bin/bash");
        }
    }else if (strcmp(argv[3], "exit") == 0){
        exit(0);
    }else if (strcmp(argv[3], "writef") == 0){
        for (int i = 0; i < atoi(argv[2]); i++){
            f = fork();
            if (f == 0){
                status = execve("writef", argv, NULL);
                exit(0);
                perror("exec failed");
            }else{
                wait(&status);
            }
        }
    }else{
        printf("Wrong command. Check the help command.\n");
    }
}
