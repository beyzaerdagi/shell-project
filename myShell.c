#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void clear();
void ls();
int exit_function();

void executeCommand(char *arr[]) {

  if (strcmp(arr[0], "clear") == 0){
    system("clear");
  } else if (strcmp(arr[0], "ls") == 0) {
    system("/bin/ls");
  } else if (strcmp(arr[0], "cat") == 0) {
    printf("cat:%s\n", arr[1]);
  } else if (strcmp(arr[0], "bash") == 0) {
    system("/bin/bash");
  } else if (strcmp(arr[0], "exit") == 0) {
    exit(0);
  }else{
    printf("%s: command not found\n",arr[0]);
  }
}

void parseSpace(char *str, char **parsed) {
  // komutlari bosluklara bakilarak bolme islemi
  for (int i = 0; i < 100; i++) {
    parsed[i] = strsep(&str, " ");
    if (parsed[i] == NULL) {
      break;
    }
    if (strlen(parsed[i]) == 0){
      i--;
    }
  }
}

int main(int argc, char *argv[]) {

  while (1) {
    char *input = (char *)malloc((100) * sizeof(char *));
    char *tmp = (char *)malloc((100) * sizeof(char *));
    char *arg = (char *)malloc((100) * sizeof(char *));
    int i = 0;

    printf("\nmyshell>>");
    scanf("%[^\n]%*c", input);

    parseSpace(input, arg); // tekli islem
    executeCommand(arg);
  }
}