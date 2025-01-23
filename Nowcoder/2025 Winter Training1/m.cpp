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
  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  auto check = [&](i64 x) -> bool {
    std::vector<i64> b(a);
    i64 max = std::ranges::max(b);
    i64 min = max;
    int f = 0;
    for (int i = 0; i < n; i++) {
      if (max - b[i] > x) {
        b[i] *= 2;
        max = std::max(b[i], max);
        if (f == 0) {
          f = 1;
        }
        min = std::min(min, b[i]);
      } else {
        if (f == 1) {
          if (std::max(b[i] * 2, max) - std::min(min, b[i] * 2) > x) {
            break;
          } else {
            b[i] *= 2;
            max = std::max(b[i], max);
          }
        }
        min = std::min(min, b[i]);
      }
    }
    if (f == 0) {
      int pos = std::min_element(b.begin(), b.end()) - b.begin();
      b[pos] *= 2; 
    }
    return std::ranges::max(b) - std::ranges::min(b) <= x;
  };

  int ans = 0;
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = std::midpoint(l, r);
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::cout << ans << "\n";
  return 0;
}