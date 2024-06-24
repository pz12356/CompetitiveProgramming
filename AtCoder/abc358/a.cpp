#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s, t;
  std::cin >> s >> t;

  std::cout << (s == "AtCoder" && t == "Land" ? "Yes\n" : "No\n");
  return 0;
}