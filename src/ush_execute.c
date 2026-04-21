#include "shell.h"
#include <stdio.h>
#include <string.h>


int ush_execute(char **args){
  // int i = 0;

  if(args[0] == NULL){
    return 1;
  }

  if (strcmp(args[0], "cd") == 0) {
    ush_cd(args);
  } else if (strcmp(args[0], "help") == 0) {
    printf("help\n");
  } else if (strcmp(args[0], "exit") == 0) {
    return 0;
  }

  return ush_launch(args);
}
