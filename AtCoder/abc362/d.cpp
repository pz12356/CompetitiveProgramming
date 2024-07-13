#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using i64 = long long;

const i64 inf = 1e18;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::vector<std::vector<std::pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--;
    v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> q;
  std::vector<bool> vis(n);
  std::vector<i64> dis(n, inf);
  dis[0] = a[0];
  q.emplace(a[0], 0);

  while (not q.empty()) {
    auto [_, u] = q.top();
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : adj[u]) {
      if (dis[u] + w + a[v] < dis[v]) {
        dis[v] = dis[u] + w + a[v];
        q.emplace(dis[v], v);
      }
    }
  }
  
  for (int i = 1; i < n; i++) {
    std::cout << dis[i] << " \n"[i == n - 1];
  }
  return 0;
}