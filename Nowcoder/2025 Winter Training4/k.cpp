#include <algorithm>
#include <iostream>

using i64 = long long;

void solve() {
  int x, y, z, a, b, c;
  std::cin >> x >> y >> z >> a >> b >> c;
  std::cout << std::max({x * a, y * b, z * c}) << "\n";
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