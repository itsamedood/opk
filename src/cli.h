#pragma once
#include "opk.h"

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

OPKArgs process_argv(int argc, char **argv);
