#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;

  int x = 0;
  for (int i = 1; i <= 31; i++) {
    x += (s[i] == '1') << (31 - i);
  }
  if (s[0] == '1')
    x = -x;

  for (int i = 31; i >= 0; i--) {
    if (i == 31 && s[0] == '1' && x != 0)
      std::cout << 1;
    else
      std::cout << (x >> i & 1);
  }
  return 0;
}