#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm> // you shouldn't use this header


size_t read_data(char** &line_array) {
  // allocate memory for string buffer
  static const int BUF_SIZE = (1024);
  char *buffer = (char*)malloc(BUF_SIZE);

  size_t count = 0;

  while (1) {
    if (!fgets(buffer, BUF_SIZE, stdin)) {
      break;
    }
    size_t length = strlen(buffer);
    std::cout << length << "bytes read" << std::endl;
    char *line = (char*)malloc(length);
    memcpy(line, buffer, length);
    
    if (line[length - 1] == '\n') {
      line[length - 1] = '\0';
    }
    
    line_array[count] = line;
    ++count;
  }

  free(buffer);
  return count;
}

void free_data(char** data, size_t count) {
  for (int index = 0; index < count; ++index) {
    free(data[index]);
  }
}

void print_line_array(char **data, size_t count) {
  // print sorted result
  for (int index = 0; index < count; ++index) {
    printf("%s\n", data[index]);
  }
}

//  overwrite string comparison operator
bool my_less(const char *lhs, const char *rhs) { return strcmp(lhs, rhs) < 0; }

void my_sort(char **begin, char **end, bool (*_less)(const char*,const char*)) {
  std::sort(begin, end, _less);
}

int main() {
  // allocate memory for your structure (array, stack, list, etc.)
  static const int MAX_LINE_COUNT = (1024 * 1024);
  char **line_array = (char**)malloc(sizeof(char*) * MAX_LINE_COUNT);
 
  int count = read_data(line_array);

  // you should replace this with your own version of sort
  //std::sort(&line_array[0], &line_array[count], my_less);
  my_sort(&line_array[0], &line_array[count], my_less);

  print_line_array(line_array, count);

  free_data(line_array, count);
  free(line_array); // release memory user for your structure (array, stack, list, etc.)

  return 0;
}
