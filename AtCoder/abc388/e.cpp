#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int ans = 0;
  int l = 0, r = n / 2;

  auto check = [&](int k) {
    for (int i = 0; i < k; i++) {
      if (a[i] * 2 > a[n - k + i]) {
        return false;
      }
    }
    return true;
  };
  while (l <= r) {
    int mid = std::midpoint(l, r);
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  std::cout << ans << "\n";
  return 0;
}