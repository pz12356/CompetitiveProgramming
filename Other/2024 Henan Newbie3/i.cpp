#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <array>

using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector adj(2 * n + 1, std::vector<std::array<int, 3>>()); 

  for (int i = 1; i <= m; i++) {
    int a, b, c, d; 
    std::cin >> a >> b >> c >> d;
    adj[a].push_back({b, c, d});
    adj[b].push_back({a, c, d});
    adj[a + n].push_back({b + n, c, 1});
    adj[b + n].push_back({a + n, c, 1});
    if (a == k && d == 0) {
      adj[a].push_back({b + n, c, 1});
    }
    if (b == k && d == 0) {
      adj[b].push_back({a + n, c, 1});
    }
  }

  std::vector<i64> dis(2 * n + 1, inf);
  std::vector<bool> vis(2 * n + 1);
  dis[1] = 0;
  std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> q;
  q.emplace(0, 1);

  while (not q.empty()) {
    auto [_, u] = q.top();
    q.pop();
    
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, c, d] : adj[u]) {
      if (d == 1) {
        if (dis[v] > dis[u] + c) {
          dis[v] = dis[u] + c;
          q.emplace(dis[v], v);
        }
      }
    }
  }

  i64 ans = std::min(dis[n], dis[2 * n]);
  if (ans == inf) ans = -1;
  std::cout << ans << "\n";
  return 0;
}