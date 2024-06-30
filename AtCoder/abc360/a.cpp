#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;

  int flag = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'R') {
      flag = 1;
    }

    if (s[i] == 'M') {
      if (flag) {
        std::cout << "Yes\n";
        break;
      } else {
        std::cout << "No\n";
      }
    }
  }
  return 0;
}