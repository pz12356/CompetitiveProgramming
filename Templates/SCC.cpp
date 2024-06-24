#include <vector>
#include <functional>

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