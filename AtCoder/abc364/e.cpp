#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int x, y;
  std::cin >> x >> y;
  std::vector<int> a(n + 1), b(n + 1);

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }

  std::vector dp(n + 1, std::vector(n + 1, std::vector<int>(x + 1, y + 1)));

  for (int i = 0; i <= x; i++) {
    dp[0][0][i] = 0;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= x; k++) {
      dp[i][0][k] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= x; k++) {
        dp[i][j][k] = std::min(dp[i - 1][j][k], dp[i][j][k]);
        if (j >= 1 && k >= a[i]) {
          dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j - 1][k - a[i]] + b[i]);
        }
      }
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    if (dp[n][i][x] <= y) {
      ans = i;
    }
  }
  ans++;
  if (ans >= n) {
    ans = n;
  }
  std::cout << ans << "\n";
  return 0;
}