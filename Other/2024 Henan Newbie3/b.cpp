#include <iostream>
#include <sstream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  int ans = 0;
  auto check = [&](std::string& str) -> bool {
    std::stringstream s;
    s << str;
    int num[4];
    char c;
    s >> num[0] >> c >> num[1] >> c >> num[2] >> c >> num[3];
    for (int i = 0; i < 4; i++) {
      if (num[i] < 0 || num[i] > 255) {
        return false;
      }
    }
    return true;
  };
  while (t--) {
    std::string s;
    std::cin >> s;
    ans += check(s);
  }
  std::cout << ans << "\n";
  return 0;
}