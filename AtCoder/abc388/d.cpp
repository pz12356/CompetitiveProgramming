#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> d(n + 10);
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    a[i] += d[i];
    d[i + 1]++;
    int max = std::min(a[i], n - i);
    a[i] -= max;
    d[i + max + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
  return 0;
}