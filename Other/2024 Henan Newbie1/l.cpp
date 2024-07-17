#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

constexpr int N = 4e5 + 1;
struct EBCC {
  int n;
  std::vector<std::vector<int>> adj;
  std::vector<int> stk;
  std::vector<int> dfn, low, bel;
  int cur, cnt;

  EBCC() {}
  EBCC(int n) { init(n); }

  void init(int n) {
    this->n = n;
    adj.assign(n, {});
    dfn.assign(n, -1);
    low.resize(n);
    bel.assign(n, -1);
    stk.clear();
    cur = cnt = 0;
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void dfs(int x, int p) {
    dfn[x] = low[x] = cur++;
    stk.push_back(x);

    for (auto y : adj[x]) {
      if (y == p) {
        continue;
      }
      if (dfn[y] == -1) {
        dfs(y, x);
        low[x] = std::min(low[x], low[y]);
      } else if (bel[y] == -1) {
        low[x] = std::min(low[x], dfn[y]);
      }
    }

    if (dfn[x] == low[x]) {
      int y;
      do {
        y = stk.back();
        bel[y] = cnt;
        stk.pop_back();
      } while (y != x);
      cnt++;
    }
  }

  std::vector<int> work() {
    for (int i = 0; i < n; i++) {
      if (dfn[i] == -1) {
        dfs(i, -1);
      }
    }
    return bel;
  }

  struct Graph {
    int n;
    std::vector<std::pair<int, int>> edges;
    std::vector<int> siz;
    std::vector<int> cnte;
  };
  Graph compress() {
    Graph g;
    g.n = cnt;
    g.siz.resize(cnt);
    g.cnte.resize(cnt);
    for (int i = 0; i < n; i++) {
      g.siz[bel[i]]++;
      for (auto j : adj[i]) {
        if (bel[i] < bel[j]) {
          g.edges.emplace_back(bel[i], bel[j]);
        } else if (i < j) {
          g.cnte[bel[i]]++;
        }
      }
    }
    return g;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  EBCC ebcc(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    ebcc.addEdge(u, v);
  }

  ebcc.work();
  auto g = ebcc.compress();

  std::vector<int> cnt(n + 1);
  for (auto x : g.siz) {
    cnt[x]++;
  }

  std::vector<int> a;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0)
      continue;
    int x = cnt[i];
    for (int j = 1; j <= x; j *= 2) {
      a.push_back(i * j);
      x -= j;
    }
    if (x > 0) {
      a.push_back(x * i);
    }
  }

  int len = a.size();

  std::vector<int> dp(n / 2 + 1);

  for (int i = 0; i < len; i++) {
    std::vector<int> ndp(dp);
    for (int j = 1; j <= n / 2; j++) {
      if (j >= a[i]) {
        ndp[j] = std::max(ndp[j], dp[j - a[i]] + a[i]);
      }
    }
    dp.swap(ndp);
  }

  i64 ans = 1LL * dp[n / 2] * (n - dp[n / 2]);
  std::cout << ans << "\n";
  return 0;
}