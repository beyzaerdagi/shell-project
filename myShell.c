#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J") 
#define BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define size sizeof(commandArr) / sizeof(char *) 

char *commandArr[] = {"exit","clear","ls","bash","cat: cat input","writef: writef -f file_name","execx: execx -t times program"}; 

// Shows available commands in the shell
void helpCommand(){

  printf("Commands: \n");

  for (int i = 0; i< size; i++){
    printf("--> %s\n", commandArr[i]);
  }
}

void execute(char **args){

    int f, status;
    // if command exit
    if (strcmp("exit", args[0]) == 0){ 
        exit(0);
    }else if (strcmp("clear", args[0]) == 0){ 
        //clear shell
        clear();
    }else if(strcmp("cat", args[0]) == 0){
        // print the input
        printf("Cat: ");
        for (int i = 1; args[i] != '\0'; i++){
            printf("%s ", args[i]);
        }
    }else if (strcmp("bash", args[0]) == 0){
        // goes to system bash
        system("/bin/bash");
    }else if(strcmp("ls", args[0]) == 0){
        // fetches the contents of the folder
        system("/bin/ls");
    }else if(strcmp("help",args[0]) == 0){
        helpCommand();
    }else if(strcmp("writef",args[0]) == 0){
        f = fork();
        if (f == 0){
            // calls the writef function
            status = execve("writef", args, NULL);
            perror("exec failed");
        }else{
            // Waits until the child process has finished
            wait(&status);
        }
    }else if(strcmp("execx",args[0]) == 0){
        f = fork();
        if (f == 0){
            // calls the execx function
            status = execve("execx", args, NULL);
            perror("exec failed");
        }else{
            wait(&status);
        }
    }else{
        printf("Wrong command. Check the help command.\n");
    }
}

//split line with token https://brennan.io/2015/01/16/write-a-shell-in-c/
char **splitLine(char *command) {

  int bufsize = BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;
  
  if (!tokens){
    fprintf(stderr, "Buffer error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(command, TOK_DELIM);
  while (token != NULL){
    tokens[position] = token;
    position++;

    if (position >= bufsize){
      bufsize += BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens){
        fprintf(stderr, "Buffer error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int main(){

    char *command = (char *)malloc((100) * sizeof(char *));
    char **param;                                    

    while (1) {

        printf("\nmyshell>>");
        scanf("%[^\n]%*c", command);
        // separated into input lines from the user
        param = splitLine(command);
        execute(param);
    }
    // Returns array retrieved with malloc
    free(command);  
    free(param);
}
