#include <iostream>
#include <map>
#include <utility>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> e(n);

  std::map<std::pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    std::cin >> e[i].first >> e[i].second;
    mp[e[i]]++;
  }

  i64 ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto [x1, y1] = e[i];
      auto [x2, y2] = e[j];
      if (x1 == x2) continue;
      if (y1 == y2) continue;
      ans += mp.contains({x1, y2}) && mp.contains({x2, y1});
    }
  }

  ans /= 2;

  std::cout << ans << "\n";
  return 0;
}