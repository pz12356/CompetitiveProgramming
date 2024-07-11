#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, a, b;
  std::cin >> n >> a >> b;

  for (int i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    if (a + b == c) {
      std::cout << i + 1 << "\n";
      return 0;
    }
  }

  return 0;
}