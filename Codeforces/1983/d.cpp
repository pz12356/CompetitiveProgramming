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

bool cal(std::vector<int> &a) {
  const int n = a.size();
  i64 res = 0;
  std::vector<int> b(a);
  std::ranges::sort(b);
  b.erase(std::unique(b.begin(), b.end()), b.end());
  auto get = [&](int x) {
    return std::lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
  };

  Fenwick<int> fen(n + 1);
  for (int i = 0; i < n; i++) {
    int l = get(a[i]);
    res += fen.rangSum(l, n);
    fen.add(l, 1);
  }
  return res % 2;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  for (int i = 0; i < n; i++)
    std::cin >> b[i];

  std::vector<int> sorted_a(a), sorted_b(b);
  std::ranges::sort(sorted_a);
  std::ranges::sort(sorted_b);
  if (sorted_a != sorted_b) {
    std::cout << "NO\n";
    return;
  }

  std::cout << (cal(a) == cal(b) ? "YES\n" : "NO\n");
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
