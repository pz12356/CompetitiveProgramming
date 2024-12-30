#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

template <class T> struct Fenwick {
  int n;
  std::vector<T> t;
  Fenwick(int n) : n(n + 1), t(n + 1) {}

  void add(int x, T v) {
    for (++x; x < n; x += x & -x)
      t[x] += v;
  }

  T sum(int x) {
    T res = 0;
    for (++x; x; x -= x & -x)
      res += t[x];
    return res;
  }
  T rangSum(int l, int r) { return sum(r) - sum(l - 1); }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b(a);
  std::sort(b.begin(), b.end());
  for (int i = 2; i <= n; i++) {
    if (b[i] == b[i - 1]) {
      std::cout << "NO\n";
      return;
    }
  }
  b.erase(std::unique(b.begin(), b.end()), b.end());

  auto f = [&](int x) -> int {
    return std::lower_bound(b.begin(), b.end(), x) - b.begin();
  };

  Fenwick<int> fen(n + 1);
  for (int i = m; i <= n; i++) {
    fen.add(f(a[i]), 1);
  }
  std::vector<int> pre1(n + 1), pre2(n + 1);
  for (int i = 1; i <= n; i++) {
    pre1[i] = pre1[i - 1] + (a[i] > a[i - 1]);
    pre2[i] = pre2[i - 1] + (a[i] < a[i - 1]);
  }

  bool ok = false;
  for (int i = m; i <= n; i++) {
    fen.add(f(a[i]), -1);
    if (pre1[i] - pre1[i - m + 1] == m - 1 || pre2[i] - pre2[i - m + 1] == m - 1) {
      int min = std::min(a[i], a[i - m + 1]);
      int max = std::max(a[i], a[i - m + 1]);
      int pos1 = f(min), pos2 = f(max);
      ok |= fen.rangSum(pos1, pos2) == 0;
    }
    fen.add(f(a[i - m + 1]), 1);
  }

  std::cout << (ok ? "YES\n" : "NO\n");
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
