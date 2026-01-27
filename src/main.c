#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;

  FILE *file = fopen("../test/index.html", "r");

  while((c = fgetc(file)) != EOF) {
    printf("%c",c);
  }

  fclose(file);
  fflush(file);

  return 0;
}