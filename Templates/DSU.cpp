#include <array>
#include <numeric>
#include <vector>

struct DSU {
  std::vector<int> f, siz;
  std::vector<std::array<int, 2>> his;

  DSU(int n) : siz(n + 1, 1), f(n + 1) { std::iota(f.begin(), f.end(), 0); }

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
    his.push_back({x, y});
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) { return siz[find(x)]; }
  int time() { return his.size(); }
  void revert(int tm) {
    while (his.size() > tm) {
      auto [x, y] = his.back();
      his.pop_back();
      f[y] = y;
      siz[x] -= siz[y];
    }
  }
};