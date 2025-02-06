#include <array>
#include <iostream>
#include <set>
#include <utility>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string a, b;
  std::cin >> a >> b;
  if (n < m) {
    std::swap(n, m);
    a.swap(b);
  }

  std::multiset<char> st1(a.begin(), a.end()), st2(b.begin(), b.end());

  int ans = 0;
  while (!st2.empty()) {
    auto it = st2.begin();
    if (st1.contains(*it)) {
      st1.extract(*it);
    } else {
      ans++;
    }
    st2.erase(it);
  }
  
  std::array<int, 26> map{};
  for (auto c : st1) {
    map[c - 'a']++;
  }

  int t = ans;
  int s = 0;
  for (int i = 0; i < 26; i++) {
    if (map[i] & 1) {
      if (t > 0) {
        t--;
      } else {
        s++;
      }
    }
  }
  if (s > 0) {
    ans += s / 2;
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