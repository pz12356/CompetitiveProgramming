#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, d;
  std::cin >> n >> d;

  std::vector<int> x(n), y(n);
  std::vector<i64> prex(n + 1), prey(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::ranges::sort(x);
  std::ranges::sort(y);

  for (int i = 0; i < n; i++) {
    prex[i + 1] = prex[i] + x[i];
    prey[i + 1] = prey[i] + y[i];
  }

  auto get = [&](int x, std::vector<i64> &pre, std::vector<int> &a) {
    int pos1 = std::upper_bound(a.begin(), a.end(), x) - a.begin();
    if (pos1 == n) {
      return 1LL * n * x - pre.back();
    }
    return 1LL * pos1 * x - pre[pos1] - 1LL * (n - pos1) * x + pre.back() - pre[pos1]; 
  };

  std::vector<i64> m;
  for (int i = y[0] - d; i <= y[n - 1] + d; i++) {
    m.push_back(get(i, prey, y));
  }

  std::ranges::sort(m);

  i64 ans = 0;
  for (int i = x[0] - d; i <= x[n - 1] + d; i++) {
    i64 sum1 = get(i, prex, x);
    if (sum1 > d) {
      continue;
    }
    ans += std::upper_bound(m.begin(), m.end(), d - sum1) - m.begin();
  }
  std::cout << ans << "\n";
  return 0;
}