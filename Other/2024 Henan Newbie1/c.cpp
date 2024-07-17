#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n);

  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    adj[i].resize(k);
    for (int j = 0; j < k; j++) {
      std::cin >> adj[i][j];
      adj[i][j]--;
    }
  }

  std::vector<int> match(n, -1);
  std::vector<bool> vis(n);

  auto dfs = [&](auto dfs, int u) -> bool {
    for (auto v : adj[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      if (match[v] == -1 || dfs(dfs, match[v])) {
        match[v] = u;
        return true;
      }
    }
    return false;
  };


  int cnt = 0;
  for (int i = 0; i < n; i++) {
    std::fill(vis.begin(), vis.end(), false);
    cnt += dfs(dfs, i);
  }

  if (cnt == n) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
    std::cout << n - cnt << "\n";
  }
  return 0;
}