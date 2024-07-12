#include <iostream>

using i64 = long long;

constexpr int mod = 998244353;

void solve() {
  int a, x;
  std::cin >> a >> x;

  if (x == 1) {
    std::cout << a % mod << "\n";
    return;
  }

  i64 ans = 1LL * a * a % mod;
  ans = ans * ((1LL * x * (x - 1) / 2) % mod) % mod;
  std::cout << ans << "\n";
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