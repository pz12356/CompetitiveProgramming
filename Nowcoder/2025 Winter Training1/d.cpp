#include <iostream>
#include <map>

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    mp[x]++;
  }
  if (n % 2) {
    std::cout << "No\n";
  } else {
    if (mp.size() == 2) {
      if (mp.begin()->second == n / 2) {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
    } else {
      std::cout << "No\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (n--) {
    solve();
  }
  return 0;
}