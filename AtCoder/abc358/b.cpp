#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, A;
  std::cin >> n >> A;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  int cur = 0;

  for (int i = 0; i < n; i++) {
    if (cur > a[i]) {
      cur = cur + A;
    } else {
      cur = a[i] + A;
    }

    std::cout << cur << "\n";
  }
  return 0;
}