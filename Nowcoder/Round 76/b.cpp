#include <algorithm>
#include <array>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::array<int, 26> cnt{};

  for (int i = 0; i < n; i++) {
    char c;
    std::cin >> c;

    cnt[c - 'a']++;
  }

  std::cout << char(std::max_element(cnt.begin(), cnt.end()) - cnt.begin() + 'a') << "\n";
  return 0;
}