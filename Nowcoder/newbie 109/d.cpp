#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;
constexpr i64 inf = 1e18;

void chmin(i64 &x, i64 y) {
  if (x > y) {
    x = y;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(n + 1), val(n + 1);

  std::vector<i64> val_all(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i] >> val[i];
    val_all[a[i]] += val[i];
  }
  std::vector<i64> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = val_all[i] + pre[i - 1];
  }

  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](int x, int y) { return a[x] < a[y]; });

  std::vector<i64> dp(n + 1, inf);
  dp[0] = 0;
  int j = 0;
  for (int x = 1; x <= n; x++) {
    int i = p[x];
    while (j < a[i]) {
      chmin(dp[j + 1], dp[j] + val_all[j + 1]);
      j++;
    }
    chmin(dp[a[i] + m - 1], dp[a[i] - 1] + b[i] + pre[a[i] + m - 1] - pre[a[i] - 1] - val[i]);
  }
  while (j < n) {
    chmin(dp[j + 1], dp[j] + val_all[j + 1]);
    j++;
  }
  std::cout << dp[n] << "\n";
  return 0;
}