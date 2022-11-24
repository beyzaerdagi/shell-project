#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Clear terminal
#define clear() printf("\033[H\033[J") 

int main(int argc, char *argv[]) {

    int f, status;

    if (strcmp(argv[3], "clear") == 0){
        clear();
    }else if (strcmp(argv[3], "ls") == 0){
        //Prints the contents of the folder up to the entered times
        for (int i = 0; i < atoi(argv[2]);i++){
            system("/bin/ls");
        }
    }else if (strcmp(argv[3], "cat") == 0){
        for (int i = 0; i < atoi(argv[2]);i++){
            printf("Cat: ");
            for (int j = 4; argv[j] != '\0'; j++){
                printf("%s ", argv[j]);
            }
            printf("\n");
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
                // When a child process finishes it exits and other child processes run
                exit(0);
                perror("exec failed");
            }else{
                // Waits until the child process has finished
                wait(&status);
            }
        }
    }else{
        printf("Wrong command. Check the help command.\n");
    }
}
