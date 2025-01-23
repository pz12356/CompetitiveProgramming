#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using i64 = long long;

constexpr int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  std::vector vis(n, std::vector<int>(m));

  auto check = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '1' &&
           vis[x][y] == 0;
  };

  std::map<int, std::set<std::pair<int, int>>> st;
  auto dfs = [&](auto &&self, int x, int y, int flag) -> void {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '0') {
        st[flag].insert({nx, ny});
      }
      if (check(nx, ny)) {
        vis[nx][ny] = true;
        self(self, nx, ny, flag);
      }
    }
  };

  int ans = n * m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check(i, j)) {
        vis[i][j] = true;
        st[cnt] = {};
        dfs(dfs, i, j, cnt);
        ans = std::min<int>(ans, st[cnt].size());
        cnt++;
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}