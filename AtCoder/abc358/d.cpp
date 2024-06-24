#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < m; i++) std::cin >> b[i];

  std::ranges::sort(a);
  std::ranges::sort(b);
  int i = 0, j = 0;
  i64 ans = 0;
  while (i < n && j < m) {
    if(a[i] < b[j]) i++;
    else {
      ans += a[i++];
      j++;
    }
  }

  if (j != m) ans = -1;

  std::cout << ans << "\n";
  return 0;
}