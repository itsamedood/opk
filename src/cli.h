#include <string.h>

typedef struct {
  int verbose;
  char *parent;
  char *email;
  char *username;
  char *password;
} OPKArgs;

OPKArgs process_argv(int argc, char **argv);
