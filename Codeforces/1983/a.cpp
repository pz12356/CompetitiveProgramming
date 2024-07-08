#include <iostream>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << i + 1 << " \n"[i == n - 1];
  }
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