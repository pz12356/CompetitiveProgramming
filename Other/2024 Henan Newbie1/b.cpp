#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> SCC(const std::vector<std::vector<int>> &g) {
  int n = g.size();
  std::vector<bool> done(n);
  std::vector<int> pos(n, -1), stack;
  std::vector<std::vector<int>> res;
  std::function<int(int)> dfs = [&](int u) {
    int low = pos[u] = stack.size();
    stack.push_back(u);
    for (int v : g[u]) {
      if (not done[v]) {
        low = std::min(low, ~pos[v] ? pos[v] : dfs(v));
      }
    }
    if (low == pos[u]) {
      res.emplace_back(stack.begin() + low, stack.end());
      for (int v : res.back()) {
        done[v] = true;
      }
      stack.resize(low);
    }
    return low;
  };
  for (int i = 0; i < n; i += 1) {
    if (not done[i]) {
      dfs(i);
    }
  }
  std::reverse(res.begin(), res.end());
  return res;
}

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    adj[i].push_back(x);
  }

  auto scc = SCC(adj);
  std::vector<int> id(n);
  int sz = scc.size();
  std::vector<i64> dp(sz);
  i64 ans = 0;

  for (int i = 0; i < sz; i++) {
    dp[i] = scc[i].size();
    for (int u : scc[i]) {
      id[u] = i;
    }
  }

  for (int i = 0; i < sz; i++) {
    for (int u : scc[i]) {
      for (int v : adj[u]) {
        if (id[v] != i) { 
          dp[id[v]] = std::max<i64>(dp[id[v]], scc[id[v]].size() + dp[i]);
        }
      }
    }
  }
  std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";

  return 0;
}