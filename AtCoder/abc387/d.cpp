#include <array>
#include <iostream>
#include <queue>
#include <vector>

using i64 = long long;
constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  int xs, ys, xg, yg;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        xs = i;
        ys = j;
      } else if (s[i][j] == 'G') {
        xg = i;
        yg = j;
      }
    }
  }

  std::vector dis(n, std::vector<std::array<int, 2>>(m, {inf, inf}));
  std::vector vis(n, std::vector<std::array<bool, 2>>(m, {0, 0}));
  dis[xs][ys][0] = dis[xs][ys][1] = 0;
  vis[xs][ys][0] = vis[xs][ys][1] = 1;

  std::queue<std::array<int, 3>> q;
  q.push({xs, ys, 0});
  q.push({xs, ys, 1});

  int dx[]{1, -1, 0, 0};
  int dy[]{0, 0, 1, -1};

  while (!q.empty()) {
    auto [x, y, st] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nst = st ^ 1;
      if (st == 0 && i < 2 || st == 1 && i >= 2) {
        continue;
      }
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#' ||
          vis[nx][ny][nst] == true) {
        continue;
      }
      dis[nx][ny][nst] = dis[x][y][st] + 1;
      q.push({nx, ny, nst});
      vis[nx][ny][nst] = true;
    }
  }

  int ans = std::min(dis[xg][yg][0], dis[xg][yg][1]);
  if (ans == inf) {
    ans = -1;
  }

  std::cout << ans << "\n";
  return 0;
}