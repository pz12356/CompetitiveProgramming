#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector a(n, std::vector<int>(m));

  if (k < std::max(n, m)) {
    std::cout << -1 << "\n";
    return 0;
  }

  for (int i = 0; i < std::min(n, m); i++) {
    a[i][i] = 1;
  }

  if (n < m) {
    for (int i = n; i < m; i++) {
      a[n - 1][i] = 1;
    }
  } else {
    for (int i = m; i < n; i++) {
      a[i][m - 1] = 1;
    }
  }

  a[n - 1][m - 1] += k - std::max(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j] << " \n"[j == m - 1];
    }
  }

  return 0;
}
