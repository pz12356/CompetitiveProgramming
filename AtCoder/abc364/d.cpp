#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::ranges::sort(a);

  while (q--) {
    int b, k;
    std::cin >> b >> k;

    int l = 0, r = 2e8 + 1;
    int res = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      int p1 =
          std::upper_bound(a.begin(), a.end(), b + mid) - a.begin() - 1;
      int p2 =
          std::lower_bound(a.begin(), a.end(), b - mid) - a.begin();
      if (p1 - p2 + 1 >= k) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    std::cout << res << "\n";
  }
  return 0;
}