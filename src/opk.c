#include <stdio.h>
#include <stdlib.h>
#include "opk.h"

void encrypt() { }
void decrypt() { }
void write_to_master() { }

const char *get_master_path() {
  #ifdef _WIN32
    return "C:\\opk\\master";
  #else
    static char path[512];
    const char *home = getenv("HOME");

    if (home) {
      snprintf(path, sizeof(path), "%s/opk/master", home);
      return path;
    }

    return "~/opk/master"; // Fallback if $HOME is missing.
  #endif
}
