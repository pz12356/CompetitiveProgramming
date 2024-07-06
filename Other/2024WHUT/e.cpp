#include <algorithm>
#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b, c;
  std::cin >> a >> b >> c;

  int ans = a / 3 + b / 3 + c / 3;

  if (a > 0 && a % 3 == 0) {
    ans--;
    a = 3;
  } else {
    a %= 3;
  }
  if (b > 0 && b % 3 == 0) {
    ans--;
    b = 3;
  } else {
    b %= 3;
  }
  if (c > 0 && c % 3 == 0) {
    ans--;
    c = 3;
  } else {
    c %= 3;
  }

  int res = std::min({a, b, c});
  res = std::max(res, a / 3 + b / 3 + c / 3);
  ans += res;
  std::cout << ans << '\n';
}