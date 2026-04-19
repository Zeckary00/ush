#include "shell.h"
#include <stdio.h>
#include <stdlib.h>


char *ush_read_line(void) {
  int buff_size = USH_BUFF_SIZE;
  char *buffer = malloc(sizeof(char) * buff_size);
  int pos = 0;
  int c = 0;

  if (!buffer) {
    (void)fprintf(stderr, "ush : allocation error.\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      buffer[pos] = '\0';
      return buffer;
    }
    buffer[pos] = (char)c;
    pos++;

    if (pos >= buff_size) {
      buff_size += USH_BUFF_SIZE;
      char *new_ptr = realloc(buffer, buff_size * sizeof(char));
      if (!new_ptr) {
        free(buffer);
        (void)fprintf(stderr, "ush: allocation error\n");
        exit(EXIT_FAILURE);
      }
      buffer = new_ptr;
    }
  }
}
