#include <iostream>
#include <map>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    mp[x]++;
  }

  i64 ans = 0;
  i64 sum = 0;
  for (auto [x, y] : mp) {
    if (y >= 3) {
      ans += 1LL * y * (y - 1) / 2 * (y - 2) / 3;
    } 
    if (y >= 2) {
      ans += 1LL * y * (y - 1) / 2 * sum;
    }
    sum += y;
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