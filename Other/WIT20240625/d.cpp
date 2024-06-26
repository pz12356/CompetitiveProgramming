#include <iostream>
#include <vector>

using i64 = long long;

std::vector<i64> pw3;

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<int> cnt;

  i64 t = n;
  while (t) {
    cnt.push_back(t % 3);
    t /= 3;
  }

  cnt.push_back(0);
  int x = 0;

  i64 ans = 0;
  for (int i = cnt.size() - 1; i >= 0; i--) {
    if (cnt[i] == 2) {
      int j = i + 1;
      while (j < cnt.size() && cnt[j] == 1) {
        j++;
      }

      ans += pw3[j];
      for (int k = j; k < cnt.size(); k++) {
        ans += pw3[k] * cnt[k];
      }
      break;
    }
  }
  if (ans == 0)
    ans = n;

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  i64 res = 1;
  while (res <= 3e18) {
    pw3.push_back(res);
    res *= 3;
  }

  std::cerr << pw3.size() << "\n";
  while (t--) {
    solve();
  }
  return 0;
}