#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ush_loop(void) {
  char *inpt = NULL;
  char **args = NULL;
  int status = 1;

  while (status) {
    printf(">>> ");
    inpt = ush_read_line();
    args = ush_lexer(inpt);
    status = ush_execute(args);

    free(inpt);
    free((void *)args);
  }
}
