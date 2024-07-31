#include <iostream>

using i64 = long long;

constexpr int N = 2000001;
i64 pre[N];

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::cout << pre[x + y] - pre[x] << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  for (int i = 1; i < N; i++) {
    pre[i] += pre[i - 1] + __builtin_popcount(i ^ (i - 1));
  }

  while (t--) {
    solve();
  }
  return 0;
}