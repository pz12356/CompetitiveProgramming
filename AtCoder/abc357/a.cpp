#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int sum = 0;
  std::cin >> sum;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    sum -= x;
    if(sum < 0) {
      std::cout << i << "\n";
      return 0;
    }
  }

  std::cout << n << "\n";
  return 0;
}