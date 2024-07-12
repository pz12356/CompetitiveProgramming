#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, x;
  std::cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    if (a == x) {
      std::cout << "YES\n";
      return 0;
    }
  }
  std::cout << "NO\n";
  return 0;
}