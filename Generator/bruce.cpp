#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int l, r;
    std::cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; i++) {
        
      res ^= i;
    }
    std::cout << res << "\n";
  }
}