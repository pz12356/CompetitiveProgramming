#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w, n;
  std::cin >> h >> w >> n;

  std::vector a(h + 1, std::vector<int>(w + 1, 1));

  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x][y] = 0;
  }

  std::vector pre(h + 1, std::vector<int> (w + 1, 1));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    }
  }

  i64 ans = 0;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (a[i][j] == 0) continue;
      int l = 1, r = std::min(i, j);
      int res = 0;
      while (l <= r) {
        int mid = (l + r) / 2;
        int sum = pre[i][j] - pre[i - mid][j] - pre[i][j - mid] + pre[i - mid][j - mid];
        if (sum == mid * mid) {
          res = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      ans += res;
    }
  }

  std::cout << ans << "\n";
  return 0;
}