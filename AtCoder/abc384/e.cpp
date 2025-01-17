#include <array>
#include <iostream>
#include <queue>

using i64 = long long;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int H, W, X;
  std::cin >> H >> W >> X;

  int P, Q;
  std::cin >> P >> Q;
  P--;
  Q--;

  std::vector S(H, std::vector<i64>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      std::cin >> S[i][j];
    }
  }

  std::vector vis(H, std::vector<bool>(W));
  std::priority_queue<std::array<i64, 3>, std::vector<std::array<i64, 3>>,
                      std::greater<>>
      pq;

  i64 sum = 0;
  auto add = [&](int x, int y) {
    vis[x][y] = true;
    sum += S[x][y];
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && !vis[nx][ny]) {
        pq.push({S[nx][ny], nx, ny});
      }
    }
  };
  add(P, Q);

  while (!pq.empty()) {
    auto [s, x, y] = pq.top();
    pq.pop();

    if (!vis[x][y] && s <= (sum - 1) / X) {
      add(x, y);
    }
  }

  std::cout << sum << "\n";

  return 0;
}