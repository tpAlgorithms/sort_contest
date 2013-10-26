#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

int main() {
  std::vector<std::string> data;

  while (!std::cin.eof()) {
    std::string line;
    std::getline(std::cin, line);
    if (!(std::cin.eof() and line.empty())) {
      data.push_back(line);
    }
  }
  
  std::sort(data.begin(), data.end());
  
  std::copy(data.begin(), data.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  
  return 0;
}
