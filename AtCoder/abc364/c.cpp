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

  i64 X, Y;
  std::cin >> X >> Y;

  std::vector<int> a(n), b(n);
  std::vector<int> p(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::iota(p.begin(), p.end(), 0);
  auto work = [&]() -> int {
    i64 x = 0, y = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      x += a[p[i]];
      y += b[p[i]];
      if (x > X || y > Y) {
        return i + 1;
      }
    }
    return n;
  };

  std::ranges::sort(p, [&](int x, int y) {
    return a[x] > a[y];
  });
  int ans = work();
  std::ranges::sort(p, [&](int x, int y) {
    return b[x] > b[y];
  });
  ans = std::min(ans, work());
  std::cout << ans << "\n";
  return 0;
}