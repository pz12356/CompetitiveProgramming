#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, t;
  std::cin >> n >> t;

  std::string s;
  std::cin >> s;
  
  std::vector<i64> x(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }

  std::vector<i64> a, b;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a.push_back(x[i]);
    } else {
      b.push_back(x[i]);
    }
  }

  std::ranges::sort(b);
  i64 ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int pos1 = std::upper_bound(b.begin(), b.end(), a[i] + 2 * t) - b.begin() - 1;
    int pos2 = std::upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    ans += std::max<int>(pos1 - pos2 + 1, 0);
  }
  std::cout << ans << "\n";
  return 0;
}