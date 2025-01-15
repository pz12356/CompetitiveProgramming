#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 n, m, sx, sy;
  std::cin >> n >> m >> sx >> sy;

  std::set<std::pair<i64, i64>> X, Y;

  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    X.emplace(x, y);
    Y.emplace(y, x);
  }

  auto erase = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
    if (x1 == x2) {
      if (y1 > y2) {
        std::swap(y1, y2);
      }
      auto it = X.lower_bound({x1, y1});
      while (it != X.end() && it->first == x1 && it->second <= y2) {
        Y.erase({it->second, it->first});
        X.erase(it);
        it = X.lower_bound({x1, y1});
      }
    } else {
      if (x1 > x2) {
        std::swap(x1, x2);
      }
      auto it = Y.lower_bound({y1, x1});
      while (it != Y.end() && it->first == y1 && it->second <= x2) {
        X.erase({it->second, it->first});
        Y.erase(it);
        it = Y.lower_bound({y1, x1});
      }
    }
  };

  for (int i = 0; i < m; i++) {
    char d;
    int c;
    std::cin >> d >> c;
    if (d == 'U') {
      erase(sx, sy, sx, sy + c);
      sy += c;
    } else if (d == 'D') {
      erase(sx, sy, sx, sy - c);
      sy -= c;
    } else if (d == 'L') {
      erase(sx - c, sy, sx, sy);
      sx -= c;
    } else {
      erase(sx + c, sy, sx, sy);
      sx += c;
    }
  }

  std::cout << sx << " " << sy << " " << n - X.size() << "\n";
  return 0;
}