#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  int si, sj;
  std::cin >> h >> w >> si >> sj;
  si--;
  sj--;

  std::vector<std::string> a(h);
  for (int i = 0; i < h; i++) {
    std::cin >> a[i];
  }

  std::string x;
  std::cin >> x;

  auto check = [&](int i, int j) -> bool {
    if (i >= 0 && i < h && j >= 0 && j < w && a[i][j] != '#') {
      return true;
    }
    return false;
  };

  for (auto c : x) {
    if (c == 'U') {
      if (check(si - 1, sj)) {
        si--;
      }
    } else if (c == 'R') {
      if (check(si, sj + 1)) {
        sj++;
      }
    } else if (c == 'D') {
      if (check(si + 1, sj)) {
        si++;
      }
    } else {
      if (check(si, sj - 1)) {
        sj--;
      }
    }
  }

  si++;
  sj++;
  std::cout << si << " " << sj << "\n";
  return 0;
}