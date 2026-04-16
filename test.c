#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("child process \n");
  } else if (pid > 0) {
    printf("parent process \n");
  } else {
    perror("error");
  }
}
