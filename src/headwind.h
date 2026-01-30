#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))

#define BACKSLASH 0x5c
#define SLASH 0x2f
#define ASTERISK 0x2a
#define DOUBLE_QUOTE 0x22
#define SINGLE_QUOTE 0x27
#define COLON 0x3a
#define SEMICOLON 0x3b
#define LINE_BREAK 0x0a
#define CARRIAGE_RETURN 0xd
#define SPACE 0x20
#define TAB 0x09
#define OPEN_CURLY 0x7b
#define CLOSE_CURLY 0x7d
#define OPEN_PAREN 0x28
#define CLOSE_PAREN 0x29
#define OPEN_BRACKET 0x5b
#define CLOSE_BRACKET 0x5d
#define DASH 0x2d
#define AT_SIGN 0x40
#define EXCLAMATION_MARK 0x21

/* 
char* parse(char *input) {

  int stack, parent, node;
  char *ast, *buffer, closingBracketStack, peekChar;
  buffer = malloc(sizeof(input));

  int bufferStart = 0;

  for(int i = 0; i < ARRAY_SIZE(input); i++) {
    char currentChar = input[i];

    if (currentChar == CARRIAGE_RETURN) {
      peekChar = input[i++];
      if (peekChar == LINE_BREAK) continue;
    }
  }

  char dest[strlen(input) + 1];
  hw__strcpy(buffer, dest);

  free(buffer);

  return dest;
} */