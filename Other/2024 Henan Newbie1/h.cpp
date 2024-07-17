#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  i64 res = std::accumulate(a.begin(), a.end(), 0LL);
  i64 ans = res + n;
  ans = std::max(ans, res - a.back() + 1LL * a.back() * n);
  std::cout << ans << "\n";
  return 0;
}