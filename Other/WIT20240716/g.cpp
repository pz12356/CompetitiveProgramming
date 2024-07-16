#include <iostream>

using i64 = long long;

i64 exgcd(i64 a, i64 b, i64&x, i64 &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  i64 d = exgcd(b, a % b, x, y);
  i64 t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 x, y;
  std::cin >> x >> y;

  if (x == 0 || y == 0) {
    if (x == 0) {
      if (y <= 2) {
        std::cout << 2 / y << " " << 1 << "\n";
      } else {
        std::cout << -1 << "\n";
      }
    } else {
      x = std::abs(x);
      if (x <= 2) {
        std::cout << 1 << " " << 2 / std::abs(x) << "\n";
      } else {
        std::cout << -1 << "\n";
      }
    }
    return 0;
  }

  i64 a, b;
  i64 g = exgcd(x, y, b, a);

  if (2 % g) {
    std::cout << -1 << "\n";
    return 0;
  }

  a *= 2 / g;
  b *= 2 / g;
  std::cout << -a << " " << b << "\n";
  return 0;
}