#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define clear() printf("\033[H\033[J") 

int main(int argc, char *argv[]) {

    if(strcmp(argv[3], "clear") == 0) {
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
        for (int i = 0; i < atoi(argv[2]);i++){
            exit(0);
        }
    }else if (strcmp(argv[3], "writef") == 0){
        for (int i = 0; i < atoi(argv[2]);i++){
            execv("writef", argv);
        }
    }else {
        for(int i = 0; i < atoi(argv[2]); i++){
            printf("%s\n", argv[3]);
        }
    }
}
