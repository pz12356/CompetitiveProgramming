#include <deque>
#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, t;
  std::cin >> n >> t;

  t = std::min(t, n);

  std::deque<int> dq;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    dq.push_back(x);
  }

  int i = 0;
  int res = 0;
  int max = dq.front();
  while (t-- >= 0) {
    if (dq.front() > max) {
      max = dq.front();
      res = i;
    }
    dq.push_front(dq.back());
    dq.pop_back();
    i++;
  }
  std::cout << res << "\n";
  return 0;
}