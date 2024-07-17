#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int ans = 0;
  if (n % 2) {
    ans++;
    n--;
  }

  while (n) {
    if (n == 2) {
      ans++;
      break;
    }
    if (n % 2) {
      n--;
      ans++;
    } else {
      n /= 2;
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}