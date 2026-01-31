#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

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
#define EQUAL 0x3D
#define HTML_ATTRIBUTE_CLASS "class=\""

void css_class_to_property(char *css_class) {

}

void get_css_classes(char *input) {

  char* class_list = (char *)malloc(_MAX_PATH);
  char* css_class_tokens;
  char last_char = HTML_ATTRIBUTE_CLASS[strlen(HTML_ATTRIBUTE_CLASS) - 1];

  int class_attr_end = 0;
  int class_start = 0;
  int character_from_file;
  int start_counting_file_characters = 0;

  int token_len = strlen(HTML_ATTRIBUTE_CLASS);
  int html_attr_class_index = 0;
  int css_class_index = 0;

  size_t max_len = 1024;
  
  // Read html file and print its content
  FILE *file = fopen(input, "rb");

  if(!file) {
    printf("File not found. Assuming input is just a string...");
    #define FILE_NOT_FOUND
  }

  // extract css classes and store them
#ifdef FILE_NOT_FOUND
  while ((character_from_file = fgetc(file)) != EOF) {
    char character = (char)character_from_file;
#else
  for(int i = 0; i < ARRAY_SIZE(input); i++) {
    char character = input[i];
#endif

    if (!start_counting_file_characters) {
      if (character == HTML_ATTRIBUTE_CLASS[html_attr_class_index]) {
        html_attr_class_index++;
        if (html_attr_class_index == token_len) {
          start_counting_file_characters = 1;
          html_attr_class_index = 0;
        }
      } else {
        html_attr_class_index = 0;
      }
    } else {
      if (character == DOUBLE_QUOTE) {
        start_counting_file_characters = 0;
        class_attr_end = 1;
      } else if (css_class_index < max_len - 1) {
        class_list[css_class_index++] = character;
      }
    }
  }

  class_list[css_class_index] = '\0';

  // Store characters inside the html class attribute
  css_class_tokens = strtok(class_list, " ");

  while(css_class_tokens != NULL) {
    printf("%s\n", css_class_tokens);
    css_class_tokens = strtok(NULL, " ");
  }

  free(class_list);
  fclose(file);
}

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