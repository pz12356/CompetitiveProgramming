#include <iostream>
#include <set>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::set<int> st{1, 2, 3, 5, 6};
  for (int i = 0; i < 7; i++) {
    int x;
    std::cin >> x;
    if (!st.contains(x)) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";
  return 0;
}