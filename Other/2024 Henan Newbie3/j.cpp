#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector a(n, std::vector<int>(n));
  std::vector b(m, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j];
    }
  }

  for (int i = 0; i < m - n + 1; i++) {
    for (int j = 0; j < m - n + 1; j++) {
      int sum = 0;
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
          sum += a[x][y] * b[i + x][j + y];
        }
      }
      std::cout << sum << " \n"[j == m - n];
    }
  }
  return 0;
}