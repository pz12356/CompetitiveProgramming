#include <iostream>
#include <string>
#include <vector>

using i64 = long long;

constexpr std::string m("uwawauwa");

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector a(n, std::vector<int>(m));

  std::vector<i64> x(n + m), y(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      x[i + j] += a[i][j];
      y[i - j + m] += a[i][j];
    }
  }
  
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = std::max(ans, x[i + j] + y[i - j + m] - a[i][j]);
    }
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