#include <iostream>
#include <map>
#include <set>
#include <string>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int m, n, q;
  std::cin >> m >> n >> q;

  std::map<std::string, std::string> mp;
  for (int i = 0; i < m; i++) {
    std::string pri, pub;
    std::cin >> pub >> pri;
    mp[pri] = pub;
  }

  std::map<std::string, std::map<std::string, std::set<std::string>>> v;
  for (int i = 0; i < n; i++) {
    std::string ip;
    int k;
    std::cin >> ip >> k;
    for (int j = 0; j < k; j++) {
      std::string user;
      int t;
      std::cin >> user >> t;
      for (int a = 0; a < t; a++) {
        std::string _pub;
        std::cin >> _pub;
        v[ip][user].insert(_pub);
      }
    }
  }  

  while (q--) {
    std::string user, ip, pri;
    std::cin >> user >> ip >> pri;
    if (v[ip].count(user) && v[ip][user].count(mp[pri])) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}