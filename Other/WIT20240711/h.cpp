#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  if (a[1] == 1) a[1]++;
  for (int i = 2; i <= n; i++) {
    if (a[i] == 1) a[i]++;
    if (a[i] % a[i - 1] == 0) {
      a[i]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
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