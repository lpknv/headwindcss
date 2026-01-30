#include "headwind.h"

void extract_css_classes_from_html(char *input);

int main(int argc, char *argv[]) {

  const char *css_class_token = "class=\"";
  int class_end = 0, class_start = 0, c, count_start = 0;
  char last_char = css_class_token[strlen(css_class_token) - 1];
  int token_len = strlen(css_class_token), j = 0, css_class_index = 0;

  size_t max_len = 1024;
  
  char *css_class_list = malloc(max_len), *buffer;


  // Read html file and print its content
  FILE *file = fopen("../test/index.html", "rb");

  // extract css classes and store them
  while ((c = fgetc(file)) != EOF) {
    char ch = (char)c;

    if (!count_start) {
      if (ch == css_class_token[j]) {
        j++;
        if (j == token_len) {
          count_start = 1;
          j = 0;
        }
      } else {
        j = 0;
      }
    } else {
      if (ch == '"') {
        count_start = 0;
        class_end = 1;
      } else if (css_class_index < max_len - 1) {
        css_class_list[css_class_index++] = ch;
      }
    }
  }

  css_class_list[css_class_index] = '\0';

  char *css_class_tokens = strtok(css_class_list, " ");

  while(css_class_tokens != NULL) {
    printf("%s\n\n", css_class_tokens);
    css_class_tokens = strtok(NULL, " ");
  }

  free(css_class_list);

  fclose(file);

  return 0;
}