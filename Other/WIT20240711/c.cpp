#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;

  std::vector<std::string> s(h);
  for (int i = 0; i < h; i++) {
    std::cin >> s[i];
  }

  auto check = [&](int i, int j, int x) -> bool {
    for (int d = -x; d <= x; d++) {
      if (i + d < 0 || i + d >= h || j + d < 0 || j + d >= w)
        return false;
      if (s[i + d][j + d] != '#')
        return false;
    }
    for (int d = -x; d <= x; d++) {
      if (i + d < 0 || i + d >= h || j - d < 0 || j - d >= w)
        return false;
      if (s[i + d][j - d] != '#')
        return false;
    }
    return true;
  };

  const int n = std::min(h, w);
  std::vector<int> res(n + 1);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int k = 1;
      while (check(i, j, k)) k++;
      if (k > 1) {
        res[k - 1]++;
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    std::cout << res[i] << " \n"[i == n];
  }
  return 0;
}