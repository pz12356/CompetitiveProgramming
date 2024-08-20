#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  if (n % 2 == 0) {
    std::cout << -1 << "\n";
  } else if (n == 1) {
    std::cout << 1 << "\n";
  } else {
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    std::reverse(a.begin() + (n - 1) / 2 , a.end());
    for (int i = 0; i < n; i++) {
      std::cout << a[i] << " \n"[i == n - 1];
    }
  }
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