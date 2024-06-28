#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  if (a.back() - a.front() < 1LL * a.back() * a.front()) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}