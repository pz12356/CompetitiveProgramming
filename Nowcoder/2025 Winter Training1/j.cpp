#include <array>
#include <cassert>
#include <iostream>
#include <numeric>

using i64 = long long;

constexpr int M = 2e5 + 1;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::array<int, M> freq{};
  
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    freq[x]++;
  }

  i64 ans = 0;
  for (int g = 1; g < M; g++) {
    for (int x = g + g; x < M; x += g) {
      if (((x - g) ^ x) == std::gcd(x - g, x)) {
        ans += 1LL * freq[x - g] * freq[x];
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}
