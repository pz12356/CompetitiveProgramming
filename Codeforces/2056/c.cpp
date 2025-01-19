#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  a[0] = a[1] = a[n - 1] = 1;
  for (int i = 2; i < n - 1; i++) {
    a[i] = i;
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}