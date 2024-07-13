#include <algorithm>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int r, g, b;
  std::cin >> r >> g >> b;

  std::string c;
  std::cin >> c;

  if (c == "Red") {
    std::cout << std::min(g, b);
  } else if (c == "Green") {
    std::cout << std::min(r, b);
  } else {
    std::cout << std::min(g, r);
  }
  return 0;
}