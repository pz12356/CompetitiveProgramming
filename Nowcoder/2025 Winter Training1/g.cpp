#include <algorithm>
#include <iostream>
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

  std::ranges::sort(a);
  
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans += std::abs(a[i] - (i + 1));
  }
  ans /= 2;
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] != i + 1) {
      i64 d = a[i] - (i + 1);
      a[i] -= d;
      a[i + 1] += d;
    }
  }
  
  if (a[n - 1] != n) {
    std::cout << -1 << "\n";
  } else {
    std::cout << ans << "\n";
  }
  return 0;
}