#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

using i64 = long long;
template <class T> constexpr T power(T a, i64 b) {
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
  constexpr MInt(i64 x) : x{norm(x % getMod())} {}

  static int Mod;
  constexpr static int getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(int Mod_) { Mod = Mod_; }
  constexpr int norm(int x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr int val() const { return x; }
  explicit constexpr operator int() const { return x; }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MInt inv() const {
    assert(x != 0);
    return power(*this, getMod() - 2);
  }
  constexpr MInt &operator*=(MInt rhs) & {
    x = 1LL * x * rhs.x % getMod();
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
};

template <> int MInt<0>::Mod = 1;

template <int V, int P> constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector pre(31, std::vector<int>(n + 1));
  std::vector pre1(31, std::vector<int>(n + 1));
  std::vector pre2(31, std::vector<Z>(n + 1));

  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < n; j++) {
      pre[i][j + 1] = pre[i][j] + (b[j] >> i & 1);
      pre1[i][j + 1] = pre1[i][j] + (a[j] >> i & 1);
      if (b[j] >> i & 1) {
        pre2[i][j + 1] = j + 1 - pre1[i][j + 1];
      } else {
        pre2[i][j + 1] = pre1[i][j + 1];
      }
      pre2[i][j + 1] += pre2[i][j];
    }
  }

  while (q--) {
    int l, r;
    std::cin >> l >> r;
    Z ans = 0;
    for (int i = 0; i < 31; i++) {
      Z t = 0;
      t += pre2[i][r] - pre2[i][l - 1];
      t -= Z(pre[i][r] - pre[i][l - 1]) * (l - 1 - pre1[i][l - 1]);
      t -= Z(r - l + 1 - (pre[i][r] - pre[i][l - 1])) * pre1[i][l - 1];
      ans += t * (1 << i);
    }
    std::cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}