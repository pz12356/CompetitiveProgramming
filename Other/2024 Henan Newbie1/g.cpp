#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using i64 = long long;
using i128 = __int128_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, k;
  i64 m;
  std::cin >> n >> m >> k;

  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;

  i128 sum = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (q.size() < k) {
      q.push(a[i]);
      res++;
      continue;
    }
    q.push(a[i]);
    sum += q.top();
    q.pop();
    if (sum >= m) {
      break;
    }
    res++;
  }
  
  std::cout << res << "\n";
  return 0;
}