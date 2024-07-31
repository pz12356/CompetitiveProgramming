#include <algorithm>
#include <iostream>

using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
  int a, b, c, n, w;
  std::cin >> a >> b >> c >> n >> w;

  i64 min = inf;

  for (int i = 0; i <= n; i++) {
    int l = 0, r = n - i;
    auto f = [&](int y) -> i64 { 
      return std::abs(1LL * i * (a - c) + 1LL * y * (b - c) + 1LL * n * c - w);
    };
    while (l < r) {
      int lm = l + (r - l) / 3;
      int rm = r - (r - l) / 3;
      if (f(lm) <= f(rm)) {
        r = rm - 1;
      } else {
        l = lm + 1;
      }
    }
    min = std::min({min, f(l), f(r)});
  }
  std::cout << min << "\n";
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