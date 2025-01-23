#include <iostream>

using i64 = long long;

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if (b - a >= d - c) {
    std::cout << a << " " << d - 1 << "\n";
    std::cout << b << " " << d << "\n";
    std::cout << b - 1 << " " << d << "\n";
  } else {
    std::cout << a << " " << c << "\n";
    std::cout << a << " " << c + 1 << "\n";
    std::cout << a + 1 << " " << d << "\n";
  }
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