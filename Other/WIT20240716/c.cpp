#include <deque>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;

  std::deque<int> dq;

  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      dq.push_back(x);
    } else {
      std::cout << dq.rbegin()[x - 1] << "\n";
    }
  }
  return 0;
}