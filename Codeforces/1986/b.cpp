#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int max = 0;
      for (auto [dx, dy] :
           std::vector<std::pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
            if (i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < m) {
              max = std::max(max, a[i + dx][j + dy]);
            }
      }
      if (max < a[i][j] && max > 0) {
        a[i][j] = max;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j] << " \n"[j == m - 1];
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