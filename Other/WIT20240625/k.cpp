#include <iostream>
#include <string>
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
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector res(n + 1, std::vector<int>());

  for (int i = 1; i <= n; i++) {
    int t = a[i];
    while (true) {
      res[i].push_back(t);
      if (std::to_string(t).size() == 1)
        break;
      int s = 0;
      while (t) {
        s += t % 10;
        t /= 10;
      }
      t = s;
    }
  }

  Fenwick<int> fen(n + 10);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l, r;
      std::cin >> l >> r;
      fen.add(l, 1);
      fen.add(r + 1, -1);
    } else {
      int x;
      std::cin >> x;
      int sum = fen.sum(x);
      if (sum >= res[x].size()) {
        std::cout << res[x].back() << "\n";
      } else {
        std::cout << res[x][sum] << "\n";
      }
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
}