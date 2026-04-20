#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ush_lexer(char *line) {
  int bufsize = TOK_BUFF_SIZE;
  int position = 0;
  char **tokens = (char **)malloc(sizeof(char *) * bufsize);
  char *token = NULL;

  if (!tokens) {
    (void)fprintf(stderr, "ush : allocation error.\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, USH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += TOK_BUFF_SIZE;
      char **new_ptr =
          (char **)realloc((void *)tokens, bufsize * sizeof(char *));
      if (!new_ptr) {
        (void)fprintf(stderr, "ush : allocation error.\n");
        exit(EXIT_FAILURE);
      }
      tokens = new_ptr;
    }
    token = strtok(NULL, USH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
