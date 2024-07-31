#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <class Info> struct SegmentTree {
  int n;
  std::vector<Info> info;
  SegmentTree() {}
  SegmentTree(int n, Info _init = Info()) { init(std::vector<Info>(n, _init)); }
  SegmentTree(const std::vector<Info> &_init) { init(_init); }
  void init(const std::vector<Info> &_init) {
    n = (int)_init.size();
    info.assign((n << 2) + 1, Info());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (l == r) {
        info[p] = _init[l - 1];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m + 1, r);
      pull(p);
    };
    build(1, 1, n);
  }
  void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (l == r) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m + 1, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) { modify(1, 1, n, p, v); }
  Info query(int p, int l, int r, int x, int y) {
    if (l > y || r < x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 1, n, l, r); }
};

struct Info {
  int len = 1;
  int max = 0;
  int lmax = 0;
  int rmax = 0;
};

Info operator+(const Info &a, const Info &b) {
  Info res;
  res.len = a.len + b.len;
  res.max = std::max({a.max, b.max, a.rmax + b.lmax});
  res.lmax = (a.max == a.len ? a.len + b.lmax : a.lmax);
  res.rmax = (b.max == b.len ? b.len + a.rmax : b.rmax);
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  SegmentTree<Info> seg(n, {1, 1, 1, 1});
  std::vector<int> st(n + 1, 1);

  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int p;
      std::cin >> p;
      st[p] ^= 1;
      Info info{1, st[p], st[p], st[p]};
      seg.modify(p, info);
    } else {
      int x, y;
      std::cin >> x >> y;
      std::cout << seg.query(x, y).max << "\n";
    }
  }
  return 0;
}