#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  if (k > n) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    std::string ans;
    if (n == k) {
      ans = std::string(n, '0');
    } else {
      for (int i = 0; i < k; i++) {
        ans.push_back("01"[i % 2]);
      }
      for (int i = k; i < n; i++) {
        if (i == k) {
          ans.push_back("01"[i % 2]);
        } else {
          ans.push_back(ans.back());
        }
      }
    }

    for (auto c : ans) {
      std::cout << c << " ";
    }
  }

  return 0;
}