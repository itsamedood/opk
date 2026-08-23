#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "opk.h"

void encrypt() { }
void decrypt() { }

void firstrun() {
  // Create ~/.opk if it doesn't exist.
  // ...

  // Create ~/.opk/master if it doesn't exist.
  // ...

  /* Prompt for master key & include text that mentions that it is NOT STORED!
  The user is 100% responsible for remembering their master key.
  Forgetting it will result in having to reset all stored data. */
  // ...
}

const char *get_master_path() {
  #ifdef _WIN32
  return "C:\\.opk\\master";
  #else
  static char path[512];
  const char *home = getenv("HOME");

  if (home) {
    snprintf(path, sizeof(path), "%s/.opk/master", home);
    return path;
  }

  return "~/.opk/master"; // Fallback if $HOME is missing.
  #endif
}

/**
 * Checks if the master file exists.
 */
bool master_exists() {
  FILE *file = fopen(get_master_path(), "r");

  if (file) {
    fclose(file);
    return true;
  } else return false;
}

bool write_to_master(OPKArgs args) {
  FILE *file = fopen(get_master_path(), "w");

  if (!file) {
    return false;
  }

  // Ay' I'm writing here!
  // ...

  fclose(file);
  return true;
}
