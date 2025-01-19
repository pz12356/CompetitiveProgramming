#include <bits/stdc++.h>

using i64 = long long;

struct Info {
  int len = 1;
  std::array<int, 32> sum{};
};

struct Tag {
  std::bitset<32> _xor{};
};

Info operator+(const Info &a, const Info &b) {
  std::array<int, 32> s{};
  for (int i = 0; i < 32; i++) {
    s[i] = a.sum[i] + b.sum[i];
  }
  return {a.len + b.len, s};
}

void apply(Info &x, Tag &a, Tag f) {
  a._xor ^= f._xor;
  for (int i = 0; i < 32; i++) {
    if (f._xor[i]) {
      x.sum[i] = x.len - x.sum[i];
    }
  }
}

template <class Info, class Tag> struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() {}
  LazySegmentTree(int n, Info _init = Info()) {
    init(std::vector<Info>(n, _init));
  }
  LazySegmentTree(const std::vector<Info> &_init) { init(_init); }
  void init(const std::vector<Info> &_init) {
    n = (int)_init.size();
    info.assign((n << 2) + 1, Info());
    tag.assign((n << 2) + 1, Tag());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (l == r) {
        info[p] = _init[l];
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
  void apply(int p, const Tag &v) { ::apply(info[p], tag[p], v); }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (l == r) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
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
    push(p);
    return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 1, n, l, r); }
  void modify(int p, int l, int r, int x, int y, const Tag &v) {
    if (l > y || r < x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    modify(2 * p, l, m, x, y, v);
    modify(2 * p + 1, m + 1, r, x, y, v);
    pull(p);
  }
  void modify(int l, int r, const Tag &v) { return modify(1, 1, n, l, r, v); }
  template <class F>
  int findFirst(int p, int l, int r, int x, int y, F &&pred) {
    if (l > y || r < x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(2 * p + 1, m + 1, r, x, y, pred);
    }
    return res;
  }
  template <class F> int findFirst(int l, int r, F &&pred) {
    return findFirst(1, 1, n, l, r, pred);
  }
  template <class F> int findLast(int p, int l, int r, int x, int y, F &&pred) {
    if (l > y || r < x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findLast(2 * p + 1, m, r, x, y, pred);
    if (res == -1) {
      res = findLast(2 * p, l, m + 1, x, y, pred);
    }
    return res;
  }
  template <class F> int findLast(int l, int r, F &&pred) {
    return findLast(1, 1, n, l, r, pred);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<Info> info(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    for (int j = 0; j < 32; j++) {
      info[i].sum[j] = x >> j & 1;
    }
  }

  auto get = [&](std::array<int, 32> t) -> i64 {
    i64 ans = 0;
    for (int i = 0; i < 32; i++) {
      ans += (1LL << i) * t[i];
    }
    return ans;
  };

  LazySegmentTree<Info, Tag> seg(info);

  int q;
  std::cin >> q;
  while (q--) {
    int op, l, r;
    std::cin >> op >> l >> r;
    if (op == 1) {
      auto res = seg.query(l, r).sum;
      std::cout << get(res) << "\n";
    } else {
      int x;
      std::cin >> x;
      seg.modify(l, r, Tag{std::bitset<32>(x)});
    }
  }
  return 0;
}