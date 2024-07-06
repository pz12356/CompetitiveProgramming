#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b, c;
  std::cin >> a >> b >> c;

  i64 pw3 = 1;
  for (int i = 1; i <= a + 2; i++) {
    pw3 *= 3;
  }

  i64 res = pw3 * b;

  if (c == 1) {
    std::cout << (res + 99) / 100 * 100 * 3;   
  } else {
    std::cout << (res * 4 + 99) / 100 * 100;
  } 

  return 0;
}