#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector p(30, std::vector<int>());
  for (int i = 0; i < n; i++) {
    p[s[i] - 'a' + 1].push_back(i + 1);
  }

  int ans = 0;
  for (int i = 1; i <= 26; i++) {
    if (p[i].size() <= 1) {
      continue;
    }
    for (int j = 1; j < std::ssize(p[i]); j++) {
      ans = std::max(ans, p[i][j - 1]);
      ans = std::max(ans, n - p[i][j] + 1);
    }
  }
  std::cout << ans << "\n";
  return 0;
}