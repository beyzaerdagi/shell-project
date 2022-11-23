#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J") 
#define BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define size sizeof(commandArr) / sizeof(char *) 

char *commandArr[] = {"exit","clear","ls","bash","cat"}; 

void helpCommand(){ //shelldeki help komutunu ifade ediyor.

  printf("Commands: \n");

  for (int i = 0; i< size; i++){
    printf("--> %s\n", commandArr[i]);
  }
}

void execute(char **args){

    int f, i;

    if (strcmp("exit", args[0]) == 0){ // if command exit
        exit(0); // terminate myshell program
    }else if (strcmp("clear", args[0]) == 0){ // if command is clear
        clear(); // clear shell
    }else if(strcmp("cat", args[0]) == 0){  // Otherwise
        printf("cat:%s\n", args[1]);
    }else if (strcmp("bash", args[0]) == 0){
        system("/bin/bash");
    }else if(strcmp("ls", args[0]) == 0){
        system("/bin/ls");
    }else if(strcmp("help",args[0]) == 0){
        helpCommand();
    }else if(strcmp("writef",args[0]) == 0){
        f = fork();
        if (f == 0){
            i = execve("writef", args, NULL);
            perror("exec failed");
        }else{
            wait(&i);
        }
    }else if(strcmp("execx",args[0]) == 0){
        f = fork();
        if (f == 0){
            i = execve("execx", args, NULL);
            perror("exec failed");
        }else{
            wait(&i);
        }
    }else{
        printf("Wrong command. Check the help command.\n");
    }
}


char **splitLine(char *komut)  //token ile satırı bölme https://brennan.io/2015/01/16/write-a-shell-in-c/
{

  int bufsize = BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;
  

  if (!tokens)
  {
    fprintf(stderr, "Buffer error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(komut, TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens)
      {
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
        param = splitLine(command);
        execute(param);
    }
    free(command); //malloc ile kullandığımız kaynağı geri iade ediyoruz 
    free(param);
}
