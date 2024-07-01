#include <assert.h>
#include <iostream>

using i64 = long long;
template <class T> constexpr T power(T a, i64 b) {
  T res{1};
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
  i64 res = a * b - i64(1.L * a * b / p) * p;
  res %= p;
  if (res < 0) {
    res += p;
  }
  return res;
}

template <i64 P> struct MInt {
  i64 x;
  constexpr MInt() : x{0} {}
  constexpr MInt(i64 x) : x{norm(x % getMod())} {}

  static i64 Mod;
  constexpr static i64 getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
  constexpr i64 norm(i64 x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr i64 val() const { return x; }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MInt inv() const { return power(*this, getMod() - 2); }
  constexpr MInt &operator*=(MInt rhs) & {
    if (getMod() < (1ULL << 31)) {
      x = x * rhs.x % int(getMod());
    } else {
      x = mul(x, rhs.x, getMod());
    }
    return *this;
  }
  constexpr MInt &operator+=(MInt rhs) & {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MInt &operator-=(MInt rhs) & {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
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
    i64 v;
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
  friend constexpr bool operator<(MInt lhs, MInt rhs) {
    return lhs.val() < rhs.val();
  }
};

template <> i64 MInt<0>::Mod = 998244353;

constexpr int P = 998244353;
using Z = MInt<P>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  Z res = 1;

  for (int i = 1; i <= k; i++) {
    res = res * (1LL * (n - 1) * (n - 1) + 1) + 1LL * n * (n + 1) - res * 2;
    res /= (1LL * n * n);
  }

  std::cout << res << "\n";
  return 0;
}