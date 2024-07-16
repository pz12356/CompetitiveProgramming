#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<std::pair<int, int>>> adj(n + 1);

  for (int i = 1; i < n; i++) {
    int a, b, x;
    std::cin >> a >> b >> x;
    adj[i].emplace_back(i + 1, a);
    adj[i].emplace_back(x, b);
  }

  std::vector<i64> dis(n + 1, inf);
  std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, i64>>> q;
  dis[1] = 0;
  q.emplace(0, 1);

  while (not q.empty()) {
    auto [_, u] = q.top();
    q.pop();
    for (auto [v, w] : adj[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        q.emplace(dis[v], v);
      }
    }
  }
  std::cout << dis[n] << "\n";
  return 0;
}