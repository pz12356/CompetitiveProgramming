#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n), w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  std::vector<std::vector<int>> mp(n + 1);
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(w[i]);
  }
  int ans = 0;
  for (auto& v : mp) {
    std::ranges::sort(v);
    for (int i = 0; i < (int)v.size() - 1; i++) {
      ans += v[i];
    }
  }

  std::cout << ans << "\n";
  return 0;
}