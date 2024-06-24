#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    double ans = 1.0;

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);

    for (int t = 0; t < 2; t++) {
        std::sort(p.begin(), p.end(), [&](int i, int j) {
            return x[i] + (t ? -1 : 1) * y[i] < x[j] + (t ? -1 : 1) * y[j];
        });
        for (int i = 1; i < n; i++) {
            int a = p[i - 1], b = p[i];
            i64 dis1 = std::abs(x[a] - x[b]) + std::abs(y[a] - y[b]);
            double dis2 = std::hypot(x[a] - x[b], y[a] - y[b]);
            ans = std::max(ans, dis1 / dis2);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(10);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}