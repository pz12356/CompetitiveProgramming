#include <iostream>
#include <string>

using i64 = long long;

constexpr std::string m("uwawauwa");

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int cnt = 0;
  int sz = m.size();
  int ans = 0;
  for (int i = sz + 1; i < n; i++) {
    cnt += s[i - sz - 1] == 'u';
    ans += (s.substr(i - sz + 1, sz) == m) * cnt;
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