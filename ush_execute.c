#include "shell.h"
#include <string.h>


int ush_execute(char **args){
  int i = 0;

  if(args[0] == NULL){
    return 1;
  }

  return ush_launch(args);
}
