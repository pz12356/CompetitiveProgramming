#include <cctype>
#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;

  int lo = 0, hi = 0;
  int n = s.size();
  for (int i = 0; i < s.size(); i++) {
    lo += s[i] >= 'a' && s[i] <= 'z';
  }
  hi = n - lo;

  if (hi > lo) {
    for (auto c : s) {
      std::cout << char(std::toupper(c));
    }
  } else {
    for (auto c : s) {
      std::cout << char(std::tolower(c));
    }
  }
  return 0;
}