#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) { init(n); }

  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) { return siz[find(x)]; }
};
using i64 = long long;

int ask(int x, int y) {
  std::cout << "? " << x << " " << y << std::endl;
  int res;
  std::cin >> res;
  return res;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> res;
  DSU dsu(n + 1);
  auto work = [&](auto &&self, int x, int y) -> void {
    if (dsu.same(x, y))
      return;
    int mid = ask(x, y);
    if (mid == x || mid == y) {
      dsu.merge(x, y);
      res.emplace_back(x, y);
      return;
    }
    self(self, x, mid);
    dsu.merge(x, mid);
    self(self, mid, y);
    dsu.merge(mid, y);
  };

  for (int i = 2; i <= n; i++) {
    work(work, 1, i);
  }
  std::cout << "! ";
  for (auto [x, y] : res) {
    std::cout << x << " " << y << " ";
  }
  std::cout << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}