#include <array>
#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;

  std::array<int, 101> mp{};

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    mp[x]++;
  }

  for (auto x : mp) {
    if (x >= 3) {
      std::cout << "YES\n";
      return 0;
    }
  }

  std::cout << "NO\n";
  return 0;
}