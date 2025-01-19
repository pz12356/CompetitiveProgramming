#include <iostream>

void solve() {
  int n, m;
  std::cin >> n >> m;

  int sum_x = m, sum_y = m;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    if (i > 0) {
      sum_x += x;
      sum_y += y;
    }
  }
  std::cout << 2 * (sum_x + sum_y) << "\n";
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