#include <cmath>
#include <iostream>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;

  while (m--) {
    if (n <= 1) {
      break;
    }
    int sqr = std::sqrt(n);
    if (sqr * sqr != n) {
      sqr++;
    }
    int half = n / 2 + n % 2;
    n = std::min(sqr, half);
  }
  n -= m + 1;
  std::cout << n << "\n";
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
