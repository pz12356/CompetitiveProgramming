#include <iostream>

int query(int x, int y) {
  std::cout << "? " << x << " " << y << "\n";
  int res;
  std::cin >> res;
  return res;
}

void solve() {
  int l = 1, r = 1000;
  while (l < r) {
    int lm = (2 * l + r) / 3;
    int rm = (l + 2 * r) / 3;
    int t = query(lm, rm);
    if (t == (lm + 1) * (rm + 1)) {
      r = lm;
    } else if (t == lm * (rm + 1)) {
      l = lm + 1;
      r = rm;
    } else if (t == lm * rm) {
      l = rm + 1;
    }
  }
  std::cout << "! " << l << std::endl;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}