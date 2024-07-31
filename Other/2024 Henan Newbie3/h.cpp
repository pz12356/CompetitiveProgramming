#include <iostream>
#include <vector>

using i64 = long long;

template <class T> void chmin(T &a, T b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, h;
  std::cin >> n >> m >> h;

  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector dp(n, std::vector(m, std::vector<int>(h + 1, n + m)));
  dp[0][0][h] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= h; k++) {
        if (i + 1 < n) {
          chmin(dp[i + 1][j][k], dp[i][j][k] + 1);
          if (k >= a[i + 1][j])
            chmin(dp[i + 1][j][k - a[i + 1][j]], dp[i][j][k]);
        }
        if (j + 1 < m) {
          chmin(dp[i][j + 1][k], dp[i][j][k] + 1);
          if (k >= a[i][j + 1]) {
            chmin(dp[i][j + 1][k - a[i][j + 1]], dp[i][j][k]);
          }
        }
      }
    }
  }

  int ans = n + m;
  for (int i = 1; i <= h; i++) {
    chmin(ans, dp[n - 1][m - 1][i]);
  }
  std::cout << ans << "\n";
  return 0;
}