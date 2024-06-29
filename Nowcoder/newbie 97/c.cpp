#include <assert.h>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;

template <class T> constexpr T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template <int P> struct MInt {
  int x;
  constexpr MInt() : x{} {}
  constexpr MInt(int x) : x{Norm(x % P)} {}

  constexpr int Norm(int x) const {
    if (x < 0) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }
  constexpr int val() const { return x; }
  explicit constexpr operator int() const { return x; }
  constexpr MInt operator-() const {
    MInt res;
    res.x = Norm(P - x);
    return res;
  }
  constexpr MInt inv() const {
    assert(x != 0);
    return power(*this, P - 2);
  }
  constexpr MInt &operator*=(MInt rhs) {
    x = 1LL * x * rhs.x % P;
    return *this;
  }
  constexpr MInt &operator+=(MInt rhs) {
    x = Norm(x + rhs.x);
    return *this;
  }
  constexpr MInt &operator-=(MInt rhs) {
    x = Norm(x - rhs.x);
    return *this;
  }
  constexpr MInt &operator/=(MInt rhs) { return *this *= rhs.inv(); }
  friend constexpr MInt operator*(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MInt operator+(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MInt operator-(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MInt operator/(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
    int v;
    is >> v;
    a = MInt(v);
    return is;
  }
  friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MInt lhs, MInt rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MInt lhs, MInt rhs) {
    return lhs.val() != rhs.val();
  }
};

template <int V, int P> constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1e9 + 7;
using Z = MInt<P>;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, x;
  std::cin >> n >> x;
  int m = std::sqrt(x);
  std::vector dp(n + 1, std::vector<Z>(m + 1));

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    Z sum = 0;
    for (int j = 1; j <= m; j++) {
      sum += dp[i - 1][j - 1];
      dp[i][j] = sum;
    }
  }

  std::cout << std::accumulate(dp[n].begin() + 1, dp[n].end(), Z(0)) << "\n";
  return 0;
}