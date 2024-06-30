#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s, t;
  std::cin >> s >> t;

  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j < i; j++) {
      std::string temp;
      for (int k = j; k < s.size(); k += i) {
        temp += s[k];
      }
      if (temp == t) {
        std::cout << "Yes\n";
        return 0;
      }
    }
  }
  std::cout << "No\n";
  return 0;
}