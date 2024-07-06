#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::string s, t;
  std::cin >> s >> t;
  s += "..";
  t += "..";

  std::unordered_map<std::string, int> mp;
  mp[s] = 0;

  std::queue<std::string> q;
  q.push(s);

  while (not q.empty()) {
    std::string u = q.front();
    q.pop();

    int pos = u.find('.');
    for (int i = pos - 2; i >= 0; i--) {
      std::string v(u);
      std::swap(v[i], v[pos]);
      std::swap(v[i + 1], v[pos + 1]);
      if (not mp.contains(v)) {
        mp[v] = mp[u] + 1;
        q.push(v);
      }
    }
    for (int i = pos + 2; i < n + 1; i++) {
      std::string v(u);
      std::swap(v[i], v[pos]);
      std::swap(v[i + 1], v[pos + 1]);
      if (not mp.contains(v)) {
        mp[v] = mp[u] + 1;
        q.push(v);
      }
    }
  }

  std::cout << (mp.contains(t) ? mp[t] : -1) << "\n";
  return 0;
}