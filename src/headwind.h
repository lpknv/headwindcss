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


void get_css_classes(char *input) {

  char* css_class_tokens;
  char last_char = HTML_ATTRIBUTE_CLASS[strlen(HTML_ATTRIBUTE_CLASS) - 1];
  
  int class_attr_end = 0;
  int class_start = 0;
  int character_from_file;
  int count_start = 0;
  
  int token_len = strlen(HTML_ATTRIBUTE_CLASS);
  int html_attr_class_index = 0;
  int css_class_index = 0;
  
  FILE *file = fopen(input, "rb");

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  char* class_list = (char*)malloc(size);

  if(!file) {
    printf("File not found. Assuming input is just a string...");
  }

  while ((character_from_file = fgetc(file)) != EOF) {
    char character = (char)character_from_file;

    if (count_start == 0) {
      if (character == HTML_ATTRIBUTE_CLASS[html_attr_class_index]) {

        html_attr_class_index++;

        if (html_attr_class_index == strlen(HTML_ATTRIBUTE_CLASS)) {
          count_start = 1;
        }
      } else {
        html_attr_class_index = 0;
      }
    } else { 
      if (character == DOUBLE_QUOTE || character == OPEN_CURLY) {
        count_start = 0;
        class_list[css_class_index++] = ' ';
      } else {
        class_list[css_class_index++] = character;
      }
    }
  }

  class_list[css_class_index] = '\0';

  printf("%s\n\n", class_list);

  free(class_list);
  fclose(file);
}
