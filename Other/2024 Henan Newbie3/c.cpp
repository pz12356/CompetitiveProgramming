#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int x;
    std::cin >> x;
    if (x == 0) {
      std::cout << 1 << " ";
    } else {
      std::cout << 2 + 1LL * x * (x - 1) << " ";
    }
  }
  return 0;
}