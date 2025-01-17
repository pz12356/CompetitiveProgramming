#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k1, k2;
  std::cin >> n >> k1 >> k2;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int m1 = *std::max_element(a.begin(), a.end() - 1);
  int m2 = a[n - 1];
  std::cout << (m1 > m2 ? "Yes" : "No");
  return 0;
}