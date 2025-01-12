#include <iostream>
#include <queue>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::priority_queue<int> q;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    q.push(x);
  }
  i64 sum = 0;
  while (!q.empty() && (m > 0 || k > 0)) {
    int top = q.top();
    q.pop();
    if (top == 0) {
      break;
    }
    if (top % 2) {
      if (k > 0) {
        q.push(top ^ 1);
        k--;
      } else {
        sum += top;
        while (!q.empty() && q.top() % 2) {
          sum += q.top();
          q.pop();
        }
      }
    } else {
      if (m > 0) {
        q.push(top / 2);
        m--;
      } else {
        sum += top;
        while (!q.empty() && q.top() % 2 == 0) {
          sum += q.top();
          q.pop();
        }
      }
    }
    cnt--;
  }
  while (!q.empty()) {
    sum += q.top();
    q.pop();
  }
  std::cout << sum << "\n";
  return 0;
}