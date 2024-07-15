#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  std::vector vis(n, std::vector<bool>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'm') {
        for (int a = -1; a <= 1; a++) {
          for (int b = -1; b <= 1; b++) {
            if (i + a >= 0 && i + a < n && j + b >= 0 && j + b < m) {
              vis[i + a][j + b] = true;
            }
          }
        }
      }
    }
  }

  std::set<std::pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        for (int a = -1; a <= 1; a++) {
          for (int b = -1; b <= 1; b++) {
            if (i + a >= 0 && i + a < n && j + b >= 0 && j + b < m) {
              if (vis[i + a][j + b] == false && s[i + a][j + b] == 'w') {
                st.insert({i, j});
              }
              if (s[i + a][j + b] == 'c') {
                st.erase({i, j});
                goto flag;
              }
            }
          }
        }
      }
    flag:
      continue;
    }
  }
  if (st.empty()) {
    std::cout << "Too cold!\n";
  } else {
    for (auto [x, y] : st) {
      std::cout << x + 1 << ' ' << y + 1 << '\n';
    }
  }
  return 0;
}
