#include <algorithm>
#include <iostream>

using i64 = long long;

void solve() {
  int x[3];
  for (int i = 0; i < 3; i++) {
    std::cin >> x[i];
  }
  std::ranges::sort(x);

  int ans = x[2] - x[0];
  std::cout << ans << "\n";
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