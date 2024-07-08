#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector a(n, std::vector<int>(m));
  std::vector b(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      b[i][j] = c - '0';
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      while (a[i - 1][j - 1] != b[i - 1][j - 1]) {
        a[i - 1][j - 1] = (a[i - 1][j - 1] + 1) % 3;
        a[i][j] = (a[i][j] + 1) % 3;
        a[i][j - 1] = (a[i][j - 1] + 2) % 3;
        a[i - 1][j] = (a[i - 1][j] + 2) % 3;
      }
    }
  }

  bool flag = true;
  for (int i = 0; i < n; i++) {
    flag &= a[i][m - 1] == b[i][m - 1];
  }
  for (int i = 0; i < m; i++) {
    flag &= a[n - 1][i] == b[n - 1][i];
  }

  std::cout << (flag ? "YES\n" : "NO\n");
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