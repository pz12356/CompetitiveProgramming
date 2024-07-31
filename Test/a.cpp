#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "Hello\n";
  }
  return 0;
}