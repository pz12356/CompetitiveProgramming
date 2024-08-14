#include <algorithm>
#include <vector>

template <class T, class F> struct SparseTable {
  int n;
  std::vector<std::vector<T>> a;
  constexpr static F f = F();
  SparseTable(const std::vector<T> &init) : n(init.size()) {
    int lg = std::__lg(n);
    a.assign(lg + 1, std::vector<T>(n));
    a[0] = init;
    for (int i = 1; i <= lg; i++) {
      for (int j = 1; j <= n - (1 << i); j++) {
        a[i][j] = f(a[i - 1][j], a[i - 1][(1 << (i - 1)) + j]);
      }
    }
  }
  T get(int l, int r) {
    int lg = std::__lg(r - l + 1);
    return f(a[lg][l], a[lg][r - (1 << lg) + 1]);
  }
};

template <class T> struct Max {
  T operator()(const T &x, const T &y) const { return std::max(x, y); }
};

template <class T> struct Min {
  T operator()(const T &x, const T &y) const { return std::min(x, y); }
};