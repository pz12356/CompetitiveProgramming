#include <iostream>

using i64 = long long;

void solve() {
  i64 l, r;
  std::cin >> l >> r;
  std::cout << r - l + 1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}