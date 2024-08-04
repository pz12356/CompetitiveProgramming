#include <bits/stdc++.h>

using i64 = long long;

constexpr int score[20]{25, 21, 18, 16, 15, 14, 13, 12, 11, 10,
                        9,  8,  7,  6,  5,  4,  3,  2,  1,  0};

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::map<int, int> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      int c, p;
      std::cin >> c >> p;
      //			std::cerr << c << " " << p << "\n";
      res[c] += score[p - 1];
    }
  }

  std::vector<std::pair<int, int>> v;
  for (auto [x, y] : res) {
    v.emplace_back(x, y);
  }
  std::sort(v.begin(), v.end(), [&](auto x, auto y) {
    return x.second == y.second ? x.first < y.first : x.second > y.second;
  });

  for (auto [x, y] : v) {
    std::cout << x << " " << y << "\n";
  }
  return 0;
}
