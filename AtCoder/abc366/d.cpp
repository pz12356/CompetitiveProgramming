#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector a(n + 1, std::vector(n + 1, std::vector<int>(n + 1)));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        std::cin >> a[i][j][k];
        a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] + a[i][j][k - 1] -
                      a[i - 1][j - 1][k] - a[i][j - 1][k - 1] -
                      a[i - 1][j][k - 1] + a[i - 1][j - 1][k - 1];
      }
    }
  }

  int q;
  std::cin >> q;

  while (q--) {
    int l1, r1, l2, r2, l3, r3;
    std::cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
    std::cout << a[r1][r2][r3] - a[l1 - 1][r2][r3] - a[r1][l2 - 1][r3] -
                     a[r1][r2][l3 - 1] + a[l1 - 1][l2 - 1][r3] +
                     a[r1][l2 - 1][l3 - 1] + a[l1 - 1][r2][l3 - 1] -
                     a[l1 - 1][l2 - 1][l3 - 1]
              << "\n";
  }
  return 0;
}