#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "cli.h"

/**
 * Processes command-line arguments.
 */
OPKArgs process_argv(int argc, char **argv) {
  bool parent = false;
  bool emailOrUsername = false;
  bool password = false;
  bool verbose = false;

  OPKArgs args = {
    false, // Verbose.
    "", // Parent.
    "", // Email or Password.
    "", // Password.
  };

  for (int i = 0; i < argc; i++) {
    char *arg = argv[i];
    if (strcmp(arg, "-help") == 0) printf(HELP_STRING);
    if (strcmp(arg, "-app") == 0) parent = true;
    if (strcmp(arg, "-eou") == 0) emailOrUsername = true;
    if (strcmp(arg, "-pwd") == 0) password = true;
    if (strcmp(arg, "-vbs") == 0) args.verbose = true;

    if (parent == true) args.parent = arg;
    if (emailOrUsername == true) args.emailOrUsername = arg;
    if (password == true) args.password = arg;

    if (args.verbose) printf("%i, %s\n", i, arg);
  }

  return args;
}
