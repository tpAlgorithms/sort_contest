#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <algorithm> // you shouldn't use this header

//  overwrite string comparison operator
bool my_less(char *lhs, char *rhs) { return strcmp(lhs, rhs) < 0; }

// define my container type
typedef char** line_array_t;


void line_array_append(line_array_t& line_array, size_t& count, char* line) {
  line_array[count] = line;
  ++count;
}

size_t read_data(
    char *data_buffer,
    line_array_t &line_array,
    void (appen_func) (line_array_t&, size_t& count, char*)) {

  size_t buffer_size = 0;
  size_t count = 0;

  while (1) {
    char *line_buffer = &data_buffer[buffer_size];
    if (scanf("%s", line_buffer) != 1) {
      break;
    }
    size_t length = strlen(line_buffer);
    
    // append pointer to line array
    // !!! you should store line pointers in structure specified in YOUR statement !!! 
    line_array_append(line_array, count, line_buffer);

    buffer_size += length + 1;
  }

  return count;
}

void print_line_array(line_array_t data, size_t count) {
  // print sorted result
  for (int index = 0; index < count; ++index) {
    printf("%s\n", data[index]);
  }
}

int main() {
  // allocate memory for string buffer
  static const int MAX_DATA_SIZE = (4 * 1024 * 1024);
  char *data_buffer = (char*)malloc(MAX_DATA_SIZE);

  // allocate memory for your structure (array, stack, list, etc.)
  static const int MAX_LINE_COUNT = (1024 * 1024);
  char **line_array = (char**)malloc(sizeof(char*) * MAX_LINE_COUNT);
 
  int count = read_data(data_buffer, line_array, line_array_append);

  // you should replace this with your own version of sort
  std::sort(&line_array[0], &line_array[count], my_less);

  print_line_array(line_array, count);

  free(line_array); // release memory user for your structure (array, stack, list, etc.)
  free(data_buffer); // release memory used for data_buffer

  return 0;
}
