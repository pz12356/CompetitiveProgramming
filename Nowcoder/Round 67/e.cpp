#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  auto get = [&](i64 x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  };

  for (int i = 0; i < n; i++) {
    i64 l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;

    i64 lo = l1 + l2, hi = r1 + r2;

    int res = get(hi);
    std::string str_r = std::to_string(hi);
    int n = str_r.size();
    for (int i = 0; i < n; ++i) {
      if (str_r[i] > '0') {
        std::string candidate_str = str_r;
        candidate_str[i]--;
        for (int j = i + 1; j < n; ++j) {
          candidate_str[j] = '9';
        }
        i64 candidate = stoll(candidate_str);
        if (candidate >= lo && candidate <= hi) {
          res = std::max(res, get(candidate));
        }
      } else {
        std::string candidate_str =
            std::to_string(hi - (i64)pow(10, n - i - 1));
        for (int j = 0; j < n - i - 1; j++) {
          candidate_str.rbegin()[i] = '9';
        }
        i64 candidate = stoll(candidate_str);
        if (candidate >= lo && candidate <= hi) {
          res = std::max(res, get(candidate));
        }
      }
    }
    std::cout << res << "\n";
  }
  return 0;
}