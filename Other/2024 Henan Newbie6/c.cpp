#include <iostream>
#include <vector>

using i64 = long long;

template <class T> void chmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector dp(m + 1, std::vector<int>(16, -1));
  int ans = 0;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int v, w;
    std::cin >> v >> w;
    std::vector ndp(dp);
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < 16; k++) {
        if (j >= v) {
          chmax(ndp[j][k], dp[j - v][((k - w) % 16 + 16) % 16] + 1);
        }
      }
      chmax(ans, ndp[j][0]);
    }
    dp.swap(ndp);
  }
  std::cout << ans << "\n";
  return 0;
}