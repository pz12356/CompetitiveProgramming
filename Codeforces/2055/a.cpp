#include <iostream>

namespace Grainrain {
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = a + b;
  if (ans & 1) {
    cout << "NO\n";
    return;
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