#include <iostream>
#include <map>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    m[x]++;
  }
  if (n == 1) {
    std::cout << 0 << "\n";
    return ;
  }
  int min = n;
  for (auto [x, y] : m) {
    min = std::min(min, n - y);
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