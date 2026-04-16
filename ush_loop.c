#include <stdio.h>
#include <string.h>
#include "shell.h"


int ush_loop(void) {
  char *inpt;
  char **args;

  while(1){
    printf(">>> ");
    inpt = ush_read_line();
    args = ush_lexer(inpt);

    if (strcmp(inpt, "exit") == 0) {
      return 0; 
    }
  }
}
