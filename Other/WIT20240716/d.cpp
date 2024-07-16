#include <iostream>
#include <map>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 N;
  std::cin >> N;

  std::map<i64, i64> m;

  auto dfs = [&](auto dfs, i64 x) -> i64 {
    if (x < 2) return 0;
    if (m.contains(x)) {
      return m[x];
    }
    return m[x] = x + dfs(dfs, x / 2) + dfs(dfs, (x + 1) / 2);
  };

  std::cout << dfs(dfs, N) << "\n";
  return 0;
}