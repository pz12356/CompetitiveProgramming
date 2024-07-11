#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;

  std::vector<std::string> a(h), b(h);
  for (int i = 0; i < h; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < h; i++) {
    std::cin >> b[i];
  }

  auto work = [&](int x, int y) -> void {
    auto u = a, v = b;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < w; j++) {
        char x = u[0][j];
        for (int k = 0; k < h - 1; k++) {
          u[k][j] = u[k + 1][j];
        }
        u[h - 1][j] = x;
      }
    }
    for (int i = 0; i < y; i++) {
      for (int j = 0; j < h; j++) {
        char x = u[j][0];
        for (int k = 0; k < w - 1; k++) {
          u[j][k] = u[j][k + 1];
        }
        u[j][w - 1] = x;
      }
    }

    if (u == v) {
      std::cout << "Yes\n";
      exit(0);
    }
  };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      work(i, j);
    }
  }
  std::cout << "No\n";
  return 0;
}