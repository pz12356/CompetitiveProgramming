#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

std::vector<int> primes;
std::vector<i64> primes_sqrare;

std::vector<bool> vis;
void init(int n) {
  vis.resize(n + 1, false);
  for (int i = 2; i <= n; i++) {
    if (vis[i] == false) {
      primes.push_back(i);
      primes_sqrare.push_back(1LL * i * i);
    }
    for (int j = 0; j < (int)primes.size() && i * primes[j] <= n; j++) {
      vis[i * primes[j]] = 1;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 N;
  std::cin >> N;

  init(1000000);
  const int n = primes.size();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    i64 a = primes_sqrare[i];
    while (j < n) {
      int b = primes[j];
      int r = std::upper_bound(primes_sqrare.begin(), primes_sqrare.end(), N / (a * b)) - primes_sqrare.begin() - 1;
      if (r <= j) break;
      ans += r - j;
      j++;
    }
  }

  std::cout << ans << "\n";
  return 0;
}