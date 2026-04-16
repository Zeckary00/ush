#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

#define USH_BUFF_SIZE 1024

char *ush_read_line(void) {
  int buff_size = USH_BUFF_SIZE;
  char *buffer = malloc(sizeof(char) * buff_size);
  int pos = 0;
  int c;

  if (!buffer) {
    fprintf(stderr, "ush : allocation error.\n");
    exit(EXIT_FAILURE);
  }

  while(1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      buffer[pos] = '\0';
      return buffer;
    } else {
      buffer[pos] = c;
    }
    pos++;

    if (pos >= buff_size) {
      buff_size += USH_BUFF_SIZE;
      buffer = realloc(buffer, buff_size);
      if (!buffer) {
        fprintf(stderr, "ush : allocation error.\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
