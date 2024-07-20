#include <array>
#include <iostream>
#include <queue>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w, Y;
  std::cin >> h >> w >> Y;

  std::vector a(h, std::vector<int>(w));
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                      std::greater<std::array<int, 3>>>
      q;
  std::vector vis(h, std::vector<bool>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cin >> a[i][j];
      if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
        q.push({a[i][j], i, j});
        vis[i][j] = true;
      }
    }
  }

  std::vector<int> ans(Y + 1);
  ans[0] = h * w;

  int dx[]{-1, 0, 1, 0};
  int dy[]{0, 1, 0, -1};

  for (int i = 1; i <= Y; i++) {
    ans[i] = ans[i - 1];
    while (!q.empty() && q.top()[0] <= i) {
      auto [z, x, y] = q.top();
      q.pop();
      ans[i]--;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny])
          continue;
        vis[nx][ny] = true;
        q.push({a[nx][ny], nx, ny});
      }
    }
  }

  for (int i = 1; i <= Y; i++) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}
