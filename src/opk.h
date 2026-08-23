#pragma once

typedef struct {
  int verbose;
  char *parent;
  char *emailOrUsername;
  char *password;
} OPKArgs;

void encrypt();
void decrypt();
bool write_to_master(OPKArgs args);
const char *get_master_path();
