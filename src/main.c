#include <stdio.h>
#include "main.h"
#include "cli.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf(HELP_STRING);
    return 0;
  }

  OPKArgs args = process_argv(argc, argv);
  return 0;
}
