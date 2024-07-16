#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b, d;
  std::cin >> a >> b >> d;

  for (int i = a; i <= b; i += d) {
    std::cout << i << " ";
  }
  return 0;
}