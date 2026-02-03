#include "headwind.h"
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]) {

  get_css_classes("../test/index.html");
  get_css_classes("../test/about.html");
  
  return 0;
}