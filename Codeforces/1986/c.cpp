#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s, c;
  std::cin >> s;
  std::vector<int> ind(m);
  for (int i = 0; i < m; i++) {
    std::cin >> ind[i];
    ind[i]--;
  }
  std::cin >> c;
  std::ranges::sort(ind);
  std::ranges::sort(c);

  std::vector<int> vis(n);
  for (int i = 0, j = 0; i < m; i++) {
    if (vis[ind[i]] == false) {
      s[ind[i]] = c[j++];
      vis[ind[i]] = true;
    } 
  }
  std::cout << s << "\n";
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