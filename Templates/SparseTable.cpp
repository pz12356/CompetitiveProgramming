#include <vector>
#include <algorithm>

template <class T>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> a;
    SparseTable(const std::vector<T> &init) : n(init.size()) {
        int lg = std::__lg(n);
        a.assign(lg + 1, std::vector<T>(n));
        a[0] = init;
        for (int i = 1; i <= lg; i++) {
            for (int j = 0; j <= n - (1 << i); j++) {
                a[i][j] = std::max(a[i - 1][j],  a[i - 1][(1 << (i - 1)) + j]);
            }
        }  	    
    }
    T get(int l, int r) {
        int lg = std::__lg(r - l + 1);
        return std::max(a[lg][l], a[lg][r - (1 << lg) + 1]);
    }
};