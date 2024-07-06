#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  a.insert(a.begin() + k, x);
  for (auto x : a) {
    std::cout << x << " ";
  }
  return 0;
}