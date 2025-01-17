#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;

  std::cout << std::min(n, 19260817 + 114514 + 1) << "\n";
  return 0;
}