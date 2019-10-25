#include <stdlib.h>
#include <stdio.h>
#include "bitstream.h"

/*
A simple base64 encoder made using bitstream.h
*/

char let[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int getlen(char *s) {
  int n = 0;
  while(s[n]) n++;
  return n;
}

char *base64enc(char *raw) {
  // Create bitStream object
  bitStream bs;
  // Get length (provided that this is a zero terminated string)
  int size = getlen(raw);
  // create bitstream from given string
  bs.openBytes(raw, size);
  // allocate space for result
  char *res = (char*)malloc(size);
  int len = 0;
  for(int i = 0; i < size * 8; i += 6) {
    // Turn each 6 bits to one charater
    res[len] = let[bs.read(i, 6)];
    len++;
  }
  return res;
}

int main() {
  char *s = (char*)malloc(128);
  printf("Enter a string: ");
  scanf("%s", s);
  char *res = base64enc(s);
  printf("Base64: %s", res);
  return 0;
}
