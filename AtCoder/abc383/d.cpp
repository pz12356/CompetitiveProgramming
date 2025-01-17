#include <cmath>
#include <iostream>
#include <vector>

using i64 = long long;

std::vector<int> minp, primes;
std::vector<int> pi;

bool isprime(int n) { return minp[n] == n; }

void sieve(int n) {
  minp.assign(n + 1, 0);
  primes.clear();

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }

    for (auto p : primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }

  pi.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    pi[i] = pi[i - 1] + isprime(i);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 N;
  std::cin >> N;

  sieve(2e6);
  i64 ans = 0;
  i64 sqrtn = std::sqrt(N);
  
  for (i64 x : primes) {
    if (x * x > sqrtn) {
      break;
    }
    if (x * x * x * x <= sqrtn) {
      ans++;
    }
    ans += pi[sqrtn / x] - pi[x];
  }
  std::cout << ans << '\n';
  return 0;
}