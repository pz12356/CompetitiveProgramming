#include <array>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using i64 = long long;

int convert(std::string str) {
  char c;
  std::stringstream s;
  int x, y, z;
  s << str;
  s >> x >> c >> y >> c >> z;
  return x * 3600 + y * 60 + z;
}

int a1 = convert("07:00:00");
int a2 = convert("09:00:00");
int b1 = convert("18:00:00");
int b2 = convert("20:00:00");
int c1 = convert("11:00:00");
int c2 = convert("13:00:00");
int d1 = convert("22:00:00");
int d2 = convert("01:00:00");
int e = convert("24:00:00");

int f(std::string &str) {
  int x = convert(str);
  if (x >= a1 && x <= a2 || x >= b1 && x <= b2) {
    return 1;
  }
  if (x >= c1 && x <= c2) {
    return 2;
  }
  if (x >= d1 && x <= e || x <= d2) {
    return 3;
  }
  return 0;
}

std::array<int, 2> getYM(std::string& date) {
  std::stringstream s;
  s << date;
  int x;
  char c;
  s >> x;
  std::array<int, 2> arr;
  arr[0] = x;
  s >> c >> x;
  arr[1] = x;
  return arr;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, h;
  std::cin >> n >> m >> h;

  std::vector<std::set<std::string>> st(4);
  for (int i = 0; i < n; i++) {
    std::string id, date, time;
    std::cin >> id >> date >> time;
    auto get = getYM(date);
    if (get[0] == m && get[1] == h) {
      st[f(time)].insert(id);
    }
  }
  for (int i = 1; i <= 3; i++) {
    std::cout << st[i].size() << " \n"[i == 3];
  }
  return 0;
}