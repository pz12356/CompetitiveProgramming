#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::string> s{"#"};

  int pw3 = 1;
  for (int i = 1; i <= n; i++) {
    std::vector<std::string> t;
    for (int j = 0; j < pw3; j++) {
      t.push_back(std::string(pw3, '.'));
    }
    std::vector<std::string> res(pw3 * 3);

    for (int j = 0; j < pw3; j++) {
      for (int k = 0; k < 3; k++) {
        res[j] += s[j];
      }
    }
    for (int j = 0; j < pw3; j++) {
      res[j + pw3] += s[j];
      res[j + pw3] += t[j];
      res[j + pw3] += s[j];
    }
    for (int j = 0; j < pw3; j++) {
      for (int k = 0; k < 3; k++) {
        res[j + pw3 * 2] += s[j];
      }
    }
    pw3 *= 3;
    s.swap(res);
  }

  for (auto str : s) {
    std::cout << str << "\n";
  }
  return 0;
}