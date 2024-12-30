#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << -1 << "\n";
    return;
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] - 1;
  }
  ans = std::min<i64>(ans, *std::max_element(a.begin(), a.end()));
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
