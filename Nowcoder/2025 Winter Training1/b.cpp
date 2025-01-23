#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> deg(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }

  int cnt = std::count(deg.begin() + 1, deg.end(), 1);
  if (cnt != 2) {
    std::cout << -1 << "\n";
  } else {
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 1) {
        std::cout << i << " ";
      }
    }
  }
  return 0;
}