#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  int cur = 1;
  for (int i = 1; i < n; i++) {
    cur = i;
    if (s[i] == s[i - 1] && s[i] == "sweet") {
      break;
    }
  }

  if (cur < n - 1) {
    std::cout << "No\n";
  } else {
    std::cout << "Yes\n";
  }
  return 0;
}