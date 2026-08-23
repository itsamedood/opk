#include <stdbool.h>
#include <stdio.h>

char *input_master_key(bool firstrun) {
  static char masterkey[256];

  printf(firstrun == true ? "Enter master key. DO NOT FORGET IT, AS IT IS NOT STORED! | " : "Enter master key: ");

  fgets(masterkey, sizeof(masterkey), stdin);
  return masterkey;
}
