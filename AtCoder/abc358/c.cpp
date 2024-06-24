#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++)
    std::cin >> s[i];

  int ans = n;

  for (int mask = 0; mask < (1 << n); mask++) {
    std::set<int> st;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        for (int j = 0; j < m; j++) {
          if (s[i][j] == 'o') {
            st.insert(j);
          }
        }
      }
    }
    if (st.size() == m) {
      ans = std::min<int>(ans, __builtin_popcount(mask));
    }
  }

  std::cout << ans << "\n";
  return 0;
}