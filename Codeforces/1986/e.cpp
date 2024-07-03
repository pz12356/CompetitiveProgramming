#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::map<int, std::vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    mp[x % k].push_back(x);
  }

  int odd = 0;
  i64 ans = 0;
  for (auto &[x, v] : mp) {
    std::ranges::sort(v);
    if (v.size() % 2) {
      odd++;
      std::vector<i64> pre(v.size() + 1);
      for (int i = 0; i < v.size(); i++) {
        pre[i + 1] = pre[i] + v[i] * (i % 2 ? 1 : -1);
      }
      i64 res = inf;
      for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
          res = std::min(res, pre[1] - pre.back());
        } else if (i == v.size() - 1) {
          res = std::min(res, pre[i]);
        } else {
          res = std::min(res, pre[i + 1] - pre.back() + pre[i]);
        }
      }
      ans += res / k;
    } else {
      for (int i = 1; i < v.size(); i += 2) {
        ans += (v[i] - v[i - 1]) / k;
      }
    }
  }
  if (odd > 1) {
    ans = -1;
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}