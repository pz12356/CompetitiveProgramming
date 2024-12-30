#include <algorithm>
#include <array>
#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::array<int, 7> a{};
  for (int i = 0; i < 7; i++) {
    std::cin >> a[i];
  }

  std::cout << *std::min_element(a.begin(), a.end()) << "\n";
  return 0;
}
