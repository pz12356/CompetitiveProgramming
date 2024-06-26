#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if (n == 1) {
    std::cout << 0 << "\n";
    return ;
  }

  std::cout << n - 1 << "\n";

  if ((a.back() + a.front()) & 1) {
    a.back() = a.front();
  } else {
    a.front() = a.back();
  }
  std::cout << 1 << " " << n << "\n";

  for (int i = 1; i < n - 1; i++) {
    if ((a[i] + a[0]) & 1) {
      std::cout << 1 << " " << i + 1 << "\n";
    } else {
      std::cout << i + 1 << " " << n << "\n";
    }
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