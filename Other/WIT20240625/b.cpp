#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  bool ok = true;

  for (int i = 0; i < n; i++) {
    int x = a[i][0] % 7;
    if (x == 0)
      x = 7;
    ok &= x + m - 1 <= 7;
    for (int j = 0; j < m; j++) {
      if (i) {
        ok &= a[i][j] == a[i - 1][j] + 7;
      }
      if (j) {
        ok &= a[i][j] == a[i][j - 1] + 1;
      }
    }
  }
  std::cout << (ok ? "Yes\n" : "No\n");
  return 0;
}