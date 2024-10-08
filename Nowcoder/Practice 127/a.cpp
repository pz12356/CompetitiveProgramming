#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  if (a.back() - a.front() > k) {
    std::cout << a.back() << "\n";
  } else {
    std::cout << a.rbegin()[1] << "\n";
  }
  return 0;
}