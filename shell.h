#ifndef __MAIN__
#define __MAIN__

#define USH_BUFF_SIZE 1024

char *ush_read_line(void);
int ush_loop(void);

typedef struct cmd {
  char *m_cmd;
  char **s_cmd;
} Commande;


#endif
