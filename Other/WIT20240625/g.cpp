#include <iostream>
#include <map>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a;

  int zero = 0;
  int pos = 0, neg = 0;
  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (x == 0 && zero >= 3) {
      continue;
    }
    a.push_back(x);
    pos += x > 0;
    neg += x < 0;
    zero += x == 0;
    mp[x]++;
  }

  if (pos >= 3 || neg >= 3) {
    std::cout << "NO\n";
    return ;
  }

  n = a.size();
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (!mp.count(a[i] + a[j] + a[k])) {
          std::cout << "NO\n";
          return ;
        }
      }
    }
  }
  std::cout << "YES\n";
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