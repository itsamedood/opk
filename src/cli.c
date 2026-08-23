#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "cli.h" // `#include "opk.h"` in here.

/**
 * Processes command-line arguments.
 *
 * Messy ahh code.
 */
OPKArgs process_argv(int argc, char **argv) {
  bool parent = false;
  bool emailOrUsername = false;
  bool password = false;
  bool verbose = false;

  OPKArgs args = {
    false, // Verbose.
    "None", // Parent.
    "None", // Email or Password.
    "None", // Password.
  };

  for (int i = 0; i < argc; i++) {
    char *arg = argv[i];
    if (strcmp(arg, "-help") == 0) printf(HELP_STRING);
    if (strcmp(arg, "-vbs") == 0) args.verbose = true;

    if (strcmp(arg, "-app") == 0) {
      parent = true;
      continue;
    }

    if (strcmp(arg, "-eou") == 0) {
      emailOrUsername = true;
      continue;
    }

    if (strcmp(arg, "-pwd") == 0) {
      password = true;
      continue;
    }

    if (parent == true) {
      args.parent = arg;
      parent = false;
    }

    if (emailOrUsername == true) {
      args.emailOrUsername = arg;
      emailOrUsername = false;
    }

    if (password == true) {
      args.password = arg;
      password = false;
    }

    if (args.verbose) printf("%i, %s\n", i, arg);
  }

  if (args.verbose) {
    printf("Parent: %s\n", args.parent);
    printf("Email/Username: %s\n", args.emailOrUsername);
    printf("Password: %s\n", args.password);
  }

  return args;
}
