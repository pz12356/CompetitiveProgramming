#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::array<int, 3> x{};
  std::array<int, 3> y{};
  std::vector<int> z;
  for (int i = 0; i < 3; i++) {
    std::cin >> x[i] >> y[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      z.push_back((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
    }
  }

  std::sort(z.begin(), z.end());
  if (z[0] + z[1] == z[2]) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}