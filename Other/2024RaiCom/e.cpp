#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> t(n + 1), d(n + 1), p(n + 1);

  for (int i = 1; i <= n; i++) {
    std::cin >> t[i] >> d[i] >> p[i];
  }

  std::vector<int> q(n + 1);
  std::iota(q.begin(), q.end(), 0);
  std::sort(q.begin() + 1, q.end(), [&](int x, int y) { return d[x] < d[y]; });

  std::vector<i64> dp(5001);
  for (int i = 1; i <= n; i++) {
    std::vector<i64> f(dp);
    int x = q[i];
    for (int k = t[x]; k <= d[x]; k++) {
      f[k] = std::max(dp[k], dp[k - t[x]] + p[x]);
    }
    dp.swap(f);
  }

  std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
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
