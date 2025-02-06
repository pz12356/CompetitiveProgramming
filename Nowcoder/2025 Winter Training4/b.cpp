#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int cnt = std::ranges::count(s, '?');
  i64 ans = 0;

  auto isValid = [&](std::string str) {
    int res1 = 0, res2 = 0;
    for (int i = 1; i < str.size(); i++) {
      auto temp = str.substr(i - 1, 2);
      res1 += temp == "01";
      res2 += temp == "10";
    }
    return res1 == res2;
  };

  auto change = [&](char &c) {
    if (c == '0') {
      c = '1';
    } else {
      c = '0';
    }
  };
  for (int mask = 0; mask < (1 << cnt); mask++) {
    std::string t(s);
    for (int i = 0, j = 0; i < n; i++) {
      if (t[i] == '?') {
        t[i] = "01"[mask >> j & 1];
        j++;
      }
    }
    for (int i = 0; i < n; i++) {
      change(t[i]);
      ans += isValid(t);
      change(t[i]);
    }
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