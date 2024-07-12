#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, L, R;
  std::cin >> n >> L >> R;

  std::string s;
  std::cin >> s;

  std::vector<int> pre(n + 1);

  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + (s[i] == '0');
  }
  std::vector dp(n + 1, std::vector<int>(n + 1));

  auto dfs = [&](auto dfs, int l, int r) -> int {
    if (l == r) {
      return 0;
    }
    if (dp[l][r])
      return dp[l][r];

    for (int k = l; k < r; k++) {
      int left = pre[k] - pre[l - 1];
      int right = r - k - (pre[r] - pre[k]);
      int c = std::abs(left - right);
      if (c >= L && c <= R) {
        dp[l][r] = std::max(dp[l][r], dfs(dfs, l, k) + dfs(dfs, k + 1, r) + 1);
      }
    }
    return dp[l][r];
  };

  std::cout << dfs(dfs, 1, n) << "\n";

  return 0;
}