#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  if (n == 2) {
    std::cout << "-1\n";
    return;
  }

  int x = 1, y = n * n;
  std::vector ans(n, std::vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) & 1) {
        ans[i][j] = y--;
      } else {
        ans[i][j] = x++;
      }
    }
  }

  if (n > 1)
    std::swap(ans[n - 1][n - 1], ans[0][0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << ans[i][j] << " \n"[j == n - 1];
    }
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