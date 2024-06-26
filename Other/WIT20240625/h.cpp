#include <iostream>
#include <vector>

using i64 = long long;

constexpr int N = 1e6;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  std::vector<int> cnt(N + 1);
  std::vector<bool> vis(N + 1);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }

  int ans = 0;

  for (int i = 1; i <= N; i++) {
    if (cnt[i] == 0) continue;
    if (cnt[i] > 1) {
      vis[i] = true;
    }
    for (int j = 2 * i; j <= N; j += i) {
      vis[j] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    ans += !vis[a[i]];
  }
  std::cout << ans << "\n";
  return 0;
}