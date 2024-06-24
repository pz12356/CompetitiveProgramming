#include <vector>

template <class T> 
struct Fenwick {
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
