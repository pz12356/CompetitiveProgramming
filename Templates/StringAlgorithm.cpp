#include <algorithm>
#include <string>
#include <vector>

std::vector<int> KMP(std::string s) {
  int n = s.size();
  std::vector<int> f(n + 1);
  for (int i = 1, j = 0; i < n; i++) {
    while (j && s[i] != s[j]) {
      j = f[j];
    }
    j += (s[i] == s[j]);
    f[i + 1] = j;
  }
  return f;
}

std::vector<int> Z(std::string s) {
  int n = s.size();
  std::vector<int> z(n + 1);
  z[0] = n;
  for (int i = 1, j = 1; i < n; i++) {
    z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }
  return z;
}

std::vector<int> manacher(std::string s) {
  std::string t = "#";
  for (auto c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  std::vector<int> r(n);
  for (int i = 0, j = 0; i < n; i++) {
    if (2 * j - i >= 0 && j + r[j] > i) {
      r[i] = std::min(r[2 * j - i], j + r[j] - i);
    }
    while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
      r[i] += 1;
    }
    if (i + r[i] > j + r[j]) {
      j = i;
    }
  }
  return r;
}