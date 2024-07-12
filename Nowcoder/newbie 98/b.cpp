#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int odd = 0, even = 0;

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    if (x % 2) {
      odd++;
    } else {
      even++;
    }
  }

  int ans = 2 * std::min(odd, even);
  
  odd -= ans;
  if (odd & 1) odd--;
  ans += odd;
  ans = n - ans;

  std::cout << ans << "\n";
  return 0;
}