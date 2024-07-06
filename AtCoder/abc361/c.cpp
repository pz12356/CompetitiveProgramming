#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int k, n;
  std::cin >> n >> k;
  std::vector<int> a(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::ranges::sort(a);

  int ans = 1e9;
  for (int i = 0; i < k; i++) {
    ans = std::min(ans, a[i + n - k - 1] - a[i]);
  }
  for (int i = n - k - 1; i < n; i++) {
    ans = std::min(ans, a[i] - a[i - n + k + 1]);
  }
  std::cout << ans << "\n";
  return 0;
}