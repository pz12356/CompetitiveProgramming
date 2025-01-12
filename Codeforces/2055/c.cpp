#include <iostream>
#include <vector>

using i64 = long long;
void solve() {
  int n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;

  std::vector a(n, std::vector<i64>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  int i = 0, j = 0;
  while (i + j < n + m - 1) {
    if (i + j == n + m - 2 || s[i + j] == 'D') {
      i64 res = 0;
      for (int x = 0; x < m; x++) {
        res -= a[i][x];
      }
      a[i][j] = res;
      i++;
    } else {
      i64 res = 0;
      for (int x = 0; x < n; x++) {
        res -= a[x][j];
      }
      a[i][j] = res;
      j++;
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