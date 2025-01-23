#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> ranges(n); 
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    ranges[i] = {{l, r}, i};
  }

  sort(ranges.begin(), ranges.end(), [](const auto &a, const auto &b) {
    return a.first.second < b.first.second;
  });

  set<int> available;
  for (int i = 1; i <= n; i++) {
    available.insert(i);
  }

  vector<int> result(n);

  for (const auto &range : ranges) {
    int l = range.first.first, r = range.first.second, index = range.second;

    auto it = available.lower_bound(l);
    if (it == available.end() || *it > r) {
      cout << -1 << endl; 
      return 0;
    }

    result[index] = *it;
    available.erase(it); 
  }

  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}