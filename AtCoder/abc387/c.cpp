#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 l, r;
  std::cin >> l >> r;

  i64 f[20][10][2][2];
  auto count = [&](i64 n) -> i64 {
    std::vector<int> digits;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    std::ranges::reverse(digits);
    memset(f, -1, sizeof(f));
    auto dfs = [&](auto &&dfs, int cnt, int mask, bool is_limit, bool is_num) -> i64 {
      if (cnt == digits.size()) {
        return is_num;
      }
      if (~f[cnt][mask][is_limit][is_num]) {
        return f[cnt][mask][is_limit][is_num];
      }
      i64 ans = 0;
      if (is_num == false) {
        ans += dfs(dfs, cnt + 1, mask, false, false);
      }
      int low = is_num ? 0 : 1;
      int high = is_limit ? digits[cnt] : 9;
      for (int i = low; i <= high; i++) {
        if (is_num) {
          if (i < mask) {
            ans += dfs(dfs, cnt + 1, mask, is_limit && i == high, true);
          }
        } else {
          ans += dfs(dfs, cnt + 1, i, is_limit && i == high, true);
        }
      }
      return f[cnt][mask][is_limit][is_num] = ans;
    };
    return dfs(dfs, 0, 0, true, false);
  };

  std::cout << count(r) - count(l - 1) << "\n";
  return 0;
}