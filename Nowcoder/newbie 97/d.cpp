#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using i64 = long long;

int euler_phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res = res / i * (i - 1);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    res = res / n * (n - 1);
  return res;
}

int power(int x, int n, int mod) {
  int res = 1 % mod;
  while (n) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, p;
  std::cin >> n >> m >> p;

  std::vector a(n, std::vector<int>(m));
  std::vector b(n, std::vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  const int phi = euler_phi(p - 1);
  std::vector c(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j];
      int n = power(2, b[i][j], phi);
      b[i][j] = power(p, n, p - 1);
      c[i][j] = a[i][j] * b[i][j] % (p - 1);
    }
  }

  std::vector dp(n, std::vector(m, std::vector<int>(p, -1)));

  dp[0][0][c[0][0]] = 0;

  std::queue<std::array<int, 3>> q;
  q.push({0, 0, c[0][0]});

  while (!q.empty()) {
    auto [x, y, z] = q.front();
    q.pop();
    for (auto [dx, dy] :
         std::vector<std::pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      int mod = (z + c[nx][ny]) % (p - 1);
      if (dp[nx][ny][mod] == -1) {
        dp[nx][ny][mod] = dp[x][y][z] + 1;
        q.push({nx, ny, mod});
      }
    }
  }

  std::cout << dp[n - 1][m - 1][0] << "\n";
  return 0;
}