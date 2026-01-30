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

void css_class_to_property(char *css_class) {

}

void get_css_classes(char *input, const char *css_attribute) {
  const char *html_class_attribute = css_attribute; // in this case 'class="'
  int class_end = 0, class_start = 0, c, count_start = 0;
  char last_char = html_class_attribute[strlen(html_class_attribute) - 1];
  int token_len = strlen(html_class_attribute), j = 0, css_class_index = 0;

  size_t max_len = 1024;
  
  char *css_class_list = malloc(max_len), *buffer;


  // Read html file and print its content
  FILE *file = fopen(input, "rb");

  if(!file) {
    printf("Error! File not found.");
    #define FILE_NOT_FOUND
  }

  // extract css classes and store them
#ifdef FILE_NOT_FOUND
  while ((c = fgetc(file)) != EOF) {
    char character_from_file = (char)c;
#else
  for(int i = 0; i < ARRAY_SIZE(input); i++) {
    char character_from_file = input[i];
#endif

    if (!count_start) {
      if (character_from_file == html_class_attribute[j]) {
        j++;
        if (j == token_len) {
          count_start = 1;
          j = 0;
        }
      } else {
        j = 0;
      }
    } else {
      if (character_from_file == last_char) {
        count_start = 0;
        class_end = 1;
      } else if (css_class_index < max_len - 1) {
        css_class_list[css_class_index++] = character_from_file;
      }
    }
  }

  css_class_list[css_class_index] = '\0';

  char *css_class_tokens = strtok(css_class_list, " ");

  while(css_class_tokens != NULL) {
    printf("%s\n", css_class_tokens);
    css_class_tokens = strtok(NULL, " ");
  }

  free(css_class_list);

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