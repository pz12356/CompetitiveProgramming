#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  i64 s;
  std::cin >> n >> s;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    a.push_back(a[i]);
  }

  std::vector<i64> pre(n * 2 + 1);
  for (int i = 0; i < 2 * n; i++) {
    pre[i + 1] = pre[i] + a[i];
  }
  auto work = [&](i64 m) -> bool {
    for (int i = 1, j = 1; i < 2 * n + 1; i++) {
      while (j <= i && pre[i] - pre[j - 1] > m) {
        j++;
      }
      if (pre[i] - pre[j - 1] == m) {
        return true;
      }
    }
    return false;
  };

  bool ans = work(s) | work(s % pre[n]);
  std::cout << (ans ? "Yes\n" : "No\n");
  return 0;
}