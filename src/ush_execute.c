#include "shell.h"
#include <stdio.h>
#include <string.h>


int ush_execute(char **args){
  // int i = 0;

  if(args[0] == NULL){
    return 1;
  }

  if (strcmp(args[0], "cd") == 0) {
    printf("cd\n");
  } else if (strcmp(args[0], "help")) {
    printf("help\n");
  } else if (strcmp(args[0], "exit")) {
    printf("exit\n");
  }

  return ush_launch(args);
}
