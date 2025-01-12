#include <iostream>
#include <vector>

namespace Grainrain {
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  int cnt = 0;
  int pos = -1;
  int de = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      cnt++;
      pos = i;
      de = b[i] - a[i];
    }
  }
  if (cnt > 1) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == pos)
      continue;
    if (a[i] - de < b[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
}; // namespace Grainrain

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int _ = 1;
  std::cin >> _;
  while (_--)
    Grainrain::solve();
  return 0;
}