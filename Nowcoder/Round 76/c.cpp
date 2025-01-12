#include <iostream>
#include <numeric>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  i64 ans = 0;
  int gcd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    gcd = std::gcd(x, gcd);
  }
  
  ans = 1LL * gcd * n;
  std::cout << ans << "\n";
  return 0;
}