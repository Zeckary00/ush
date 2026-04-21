#include "shell.h"
#include <stdio.h>
#include <unistd.h>


int ush_cd(char **args) {
  if(args[1] == NULL) {
    fprintf(stderr, "ush : expected argument to \"cd\"\n");
  } else {
    if(chdir(args[1]) != 0) {
      perror("ush");
    }
  }
  return 1;
}

int ush_help(char **args) {
  printf("this is the help command");
  return 1;
}

