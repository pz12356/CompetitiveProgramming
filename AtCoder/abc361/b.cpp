#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a[6], b[6];
  for (int i = 0; i < 6; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < 6; i++) {
    std::cin >> b[i];
  }

  for (int i = 0; i < 3; i++) {
    if (a[i] > b[i]) {
      std::swap(a[i], b[i]);
    }
    if (a[i + 3] > b[3 + i]) {
      std::swap(a[i + 3], b[i + 3]);
    }
    if (b[i] >= a[i + 3] || b[i + 3] <= a[i]) {
      std::cout << "No\n";
      return 0;
    }
  }
  std::cout << "Yes\n";
  return 0;
}