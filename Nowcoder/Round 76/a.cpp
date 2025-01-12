#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int ans = (n / 7 * 5 + n % 7 - (n % 7 > 5 ? n % 7 - 5 : 0)) * 3;
  std::cout << ans << "\n";
  return 0;
}