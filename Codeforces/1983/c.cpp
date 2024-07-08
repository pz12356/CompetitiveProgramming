#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(3, std::vector<int>(n));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector<int> p{0, 1, 2};
  i64 tot = std::accumulate(a[0].begin(), a[0].end(), 0LL);

  do {
    i64 sum1 = 0, sum2 = 0, sum3 = 0;
    int l[3]{};
    int r[3]{};
    l[p[0]] = 0;
    for (int i = l[p[0]]; i < n; i++) {
      sum1 += a[p[0]][i];
      if (sum1 >= (tot + 2) / 3) {
        r[p[0]] = i;
        l[p[1]] = i + 1;
        break;
      }
    }
    for (int i = l[p[1]]; i < n; i++) {
      sum2 += a[p[1]][i];
      if (sum2 >= (tot + 2) / 3) {
        r[p[1]] = i;
        l[p[2]] = i + 1;
        break;
      }
    }
    for (int i = l[p[2]]; i < n; i++) {
      sum3 += a[p[2]][i];
      if (sum3 >= (tot + 2) / 3) {
        r[p[2]] = i;
        break;
      }
    }
    if (sum1 >= (tot + 2) / 3 && sum2 >= (tot + 2) / 3 && sum3 >= (tot + 2) / 3) {
      for (int i = 0; i < 3; i++) {
        std::cout << l[i] + 1 << " " << r[i] + 1 << " ";
      }
      std::cout << "\n";
      return;
    }
  } while (std::next_permutation(p.begin(), p.end()));
  std::cout << -1 << "\n";
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