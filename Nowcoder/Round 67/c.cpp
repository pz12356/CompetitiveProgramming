#include <iostream>
#include <string>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, C;
  std::cin >> n >> C;

  int len_C = std::to_string(C).length();
  int ans = 0;
  for (int i = 0; i <= C; i++) {
    int len = std::to_string(i).length() + std::to_string(C - i).length();
    len += 2 + len_C;
    ans += len == n;
  }
  std::cout << ans << "\n";
  return 0;
}