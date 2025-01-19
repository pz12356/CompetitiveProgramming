#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  std::vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    int cnt = std::count(a[i].begin() + i, a[i].end(), 1);
    for (int j = n - 1; j >= 0; j--) {
      if (ans[j] == -1) {
        if (cnt == 0) {
          ans[j] = i;
          break;
        } else {
          cnt--;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] + 1 << " \n"[i == n - 1];
  }
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