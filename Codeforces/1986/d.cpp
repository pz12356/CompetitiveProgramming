#include <algorithm>
#include <iostream>

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  if (n == 2) {
    if (s[0] == '0') {
      std::cout << s[1] << "\n";
    } else {
      std::cout << s << "\n";
    }
    return;
  }

  auto cal = [&](std::string t) {
    int res = 0;
    int cur = 1;
    for (int i = 0; i < t.length(); i++) {
      int b = t[i] - '0';
      if (cur * b <= cur + b) {
        cur *= b;
      } else {
        res += cur;
        cur = b;
      }
    }
    res += cur;
    return res;
  };
  int res = inf;
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      int x = (s[0] - '0') * 10 + s[1] - '0';
      int y = cal(s.substr(i + 1));
      res = std::min({res, x * y, x + y});
    } else if (i == n - 1) {
      int x = (s[n - 2] - '0') * 10 + s[n - 1] - '0';
      int y = cal(s.substr(0, n - 2));
      res = std::min({res, x * y, x + y});
    } else {
      int x = cal(s.substr(0, i - 1));
      int y = cal(s.substr(i + 1));
      int z = (s[i - 1] - '0') * 10 + s[i] - '0';
      res = std::min({res, x * z + y, x + y * z, x * z * y, x + z + y});
    }
  }
  std::cout << res << "\n";
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