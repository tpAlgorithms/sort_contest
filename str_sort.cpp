#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

int main() {
  const size_t MAX_SIZE = 256;
  std::vector<std::string> data;

  char buff[MAX_SIZE];
  while (1) {
    if (scanf("%s", buff) != 1) {
      break;
    }

    data.push_back(buff);
  }
  
  std::sort(data.begin(), data.end());
  
  std::copy(data.begin(), data.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  
  return 0;
}
