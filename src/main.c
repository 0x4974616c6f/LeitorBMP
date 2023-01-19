#include "../include/bmp.h"
#include <stdio.h>
#include <stdlib.h>

BFHeader bf;

int main(int argc, char *argv[]) {
  FILE *fp;
  char arg[] = "C:\\Users\\italo\\Desktop\\1.bmp";

  fp = fopen(arg, "rb");

  if (!fp) {
    printf("Not open image");
    return (0);
  }

  fillHeader(&bf, fp);

  printf("%c%cX\n", bf.signature[0], bf.signature[1]);
  printf("%dX\n", bf.imageSize);
  printf("%hdX\n", bf.reserved1);
  printf("%hdX\n", bf.reserved2);
  printf("%dX\n", bf.pixelDataOffset);

  return (0);
}
