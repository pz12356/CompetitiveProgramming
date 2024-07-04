#include <iostream>
#include <vector>

using i64 = long long;
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
    dfs(0, -1);
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

void solve() {
  int n, m;
  std::cin >> n >> m;

  EBCC g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g.addEdge(u, v);
  }

  g.work();
  auto f = g.compress();
  std::vector<std::vector<int>> adj(f.n);
  for (auto [u, v] : f.edges) {
    // std::cerr << "u = " << u << " siz[u] = " << f.siz[u] << " v = " << v
    //           << " siz[v] =  " << f.siz[v] << "\n";
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> siz(f.n);
  i64 ans = 0;
  auto dfs = [&](auto &&self, int x, int p) -> void {
    siz[x] = f.siz[x];
    for (auto y : adj[x]) {
      if (y == p) {
        continue;
      }
      self(self, y, x);
      siz[x] += siz[y];
      ans = std::max(ans, 1LL * siz[y] * (n - siz[y]));
    }
  };
  dfs(dfs, 0, -1);

  ans = 1LL * n * (n - 1) / 2 - ans;
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
