#include <cstdio>

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

int main() {
  std::vector<int> data;
  //size_t num;
  
//  std::cin >> num;
  
  
//  for (size_t i = 0; i < num; ++i) {
  while (std::cin.good()) {
    std::string line;
    std::getline(std::cin, line);
    
    if (!line.empty()) {
      data.push_back(atoi(line.c_str()));
    }
  }
  
  std::sort(data.begin(), data.end());
  
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
  
  return 0;
}
