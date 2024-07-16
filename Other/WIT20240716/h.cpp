#include <iostream>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string a, b, c;
  std::cin >> a >> b >> c;

  for (int i = 0; i < n; i++) {
    if (c[i] != a[i] && c[i] != b[i]) {
      std::cout << "YES\n";
      return ;
    }
  }
  std::cout << "NO\n";
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