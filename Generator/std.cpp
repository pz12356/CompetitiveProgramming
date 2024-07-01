#include <iostream>

using i64 = long long;

void solve() {
  i64 l, r;
  std::cin >> l >> r;
  
  auto get = [&](i64 x) -> i64 {
    int mod = (x + 1) % 4;
    i64 res = 0;
    while (mod) {
      mod--;
      res ^= x;
      x--;
    }
    return res;
  };

  std::cout << (get(r) ^ get(l - 1)) << "\n";
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