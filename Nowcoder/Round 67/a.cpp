#include <cctype>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::string low, up, digit;
  for (auto c : s) {
    if (std::isdigit(c)) {
      digit += c;
    } else if (islower(c)) {
      low += c;
    } else {
      up += c;
    }
  }
  std::string ans = low + digit + up;
  std::cout << ans << "\n";
  return 0;
}