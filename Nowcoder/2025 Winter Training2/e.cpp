#include <iostream>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (n == m || n - m > 26) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::string ans;
  for (int i = 0; i < n - m; i++) {
    ans += char('a' + i % 26);
  }
  for (int i = 0; i < m; i++) {
    ans += ans[i];
  }
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