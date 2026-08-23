#pragma once

#define HELP_STRING "\
OPK\n\
Usage: (without <>, and order does not matter.)\n\
  opk -help | opk -h\n\
  opk [-vbs] <-app <name> -eou <emailORusername> -pwd <password>>\n\
\n\
Flags:\n\
  -app    |   App/website this data is for.\n\
  -eou    |   Email or Username.\n\
  -pwd    |   Password, the most important.\n\
  -vbs    |   Verbose debug info.\n\
  -help   | Display this menu.\n"

typedef struct {
  int verbose;
  char *parent;
  char *emailOrUsername;
  char *password;
} OPKArgs;

OPKArgs process_argv(int argc, char **argv);
