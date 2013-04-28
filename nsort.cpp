#include <cstdio>
#include <vector>
#include <algorithm>

typedef int data_type;

/*
// old school C interface  
typedef int data_type;

your_sort(data_type *data_ptr, int *size) {
  // some sensible code
  
  // for (int index = 0; indx < data.size; ++index) {
  //   ...
  // }
}
*/

/*
// Object oriented CXX interface
struct your_container_type {
  int *data_ptr;
  int size;
};

your_sort(your_container_type& data) {
  // some sensible code
  
  // for (int index = 0; indx < data.size; ++index) {
  //   ...
  // }
}
*/

/*
// iterator oriented CXX interface
typedef int* your_iterator_type;

your_sort(your_iterator_type begin, your_iterator_type end) {
  // some sensible code
  // for (your_iterator_type it = begin; it != end; ++it) {
  //   ...
  // }
}
*/

int main() {
  const int MAX_SIZE = 1024 * 1024;
  data_type data_array[MAX_SIZE];
  int count = 0;

  //std::vector<int> data;
  
  // read data from stdin  
  while (true) {
    int value;
    if (scanf("%d", &value) != 1) {
      break; 
    }
    //data.push_back(value);
    data_array[count] = value;
    ++count;
  }
  
  // you should replace library sort with your oun version
  // examples:
  // your_sort(&data[0], data.size()); // old school C interface
  // your_sort(data); // pass reference to container object
  // your_sort(data.begin(), data.end()); // iterator interface
  
  // std::sort(data.begin(), data.end()); // std::vector variant
  std::sort(&data_array[0], &data_array[count]);

  // print result to stdout 
  for (int index = 0; index < count; ++index) {
    printf("%d\n", data_array[index]);
  } 
  
  return 0;
}
