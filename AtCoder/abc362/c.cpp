#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }

  i64 suml = std::accumulate(l.begin(), l.end(), 0LL);
  i64 sumr = std::accumulate(r.begin(), r.end(), 0LL);
  if (suml > 0 || sumr < 0) {
    std::cout << "No\n";
    return 0;
  }
  std::cout << "Yes\n";

  std::vector<i64> ans(n);
  i64 sum = suml;
  for (int i = 0; i < n; i++) {
    ans[i] = l[i];
    if (sum < 0) {
      i64 temp = sum;
      sum = std::min<i64>(0, sum - l[i] + r[i]);
      if (sum < 0) {
        ans[i] = r[i];
      } else if (sum >= 0) {
        ans[i] = l[i] + std::abs(temp);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}