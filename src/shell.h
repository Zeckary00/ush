#ifndef USH_SHELL_H
#define USH_SHELL_H

enum {
  USH_BUFF_SIZE = 1024,
  TOK_BUFF_SIZE = 64,
};

#define USH_TOK_DELIM " \t\n\r\a"

char *ush_read_line(void);
char **ush_lexer(char *line);
void ush_loop(void);
int ush_launch(char **args);
int ush_execute(char **args);

int ush_cd(char **args);

int ush_help(char **args);

typedef struct cmd {
  char *m_cmd;
  char **s_cmd;
} Commande;


#endif
