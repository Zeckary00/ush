#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int ush_launch(char **args) {
  pid_t pid = 0;
  pid_t wpid = 0;
  int status = 0;
  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("ush");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("ush");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}
