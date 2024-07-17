#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  i64 res = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    res ^= a[i];
  }

  i64 ans = res;
  for (int i = 0; i < n; i++) {
    for (int x = 1; x <= n / (i + 1); x++) {
      ans = std::max(ans, res ^ a[i] ^ (a[i] + x));
      ans = std::max(ans, res ^ a[i] ^ (1LL * a[i] * x));
    }
  }
  std::cout << ans << "\n";
  return 0;
}