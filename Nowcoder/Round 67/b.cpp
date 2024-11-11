#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    i64 am = 1LL * c * b / d;
    if (1LL * am * d == 1LL * c * b) {
      am--;
    }
    std::cout << a - am << ' ';
  }
  return 0;
}