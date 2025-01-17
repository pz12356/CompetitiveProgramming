#include <iostream>
#include <set>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;

  std::vector<int> ans(n + 1);
  std::set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }

  int cnt = 1;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l, r;
      std::cin >> l >> r;
      auto it = st.lower_bound(l);
      while (!st.empty() && it != st.end() && *it <= r) {
        ans[*it] = cnt++;
        st.erase(it);
        it = st.lower_bound(l);
      }
    } else {
      int x;
      std::cin >> x;
      std::cout << ans[x] << "\n";
    }
  }
  return 0;
}