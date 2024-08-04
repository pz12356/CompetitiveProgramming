#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	
	std::vector<int> hot(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> hot[i];
	}
	std::vector adj(n + 1, std::vector<std::pair<int, int>>());
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	std::vector<int> dis(n + 1, inf);
	dis[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.emplace(0, s);
	
	while (not q.empty()) {
		auto [_, u] = q.top();
		q.pop();
		for (auto [v, w] : adj[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.emplace(dis[v], v);
			}
		}
	}
	
	if (dis[t] == inf) {
		std::cout << "Impossible\n";
		exit(0);
	}
	
	int min = dis[t];
	std::cout << min << " ";
	
	int l = 0, r = *max_element(hot.begin(), hot.end());
	int res = 0;
	
	auto check = [&](int mid) -> bool {
		std::fill(dis.begin(), dis.end(), inf);
		dis[s] = 0;
		q.emplace(0, s);
		assert(not q.empty());
		while (not q.empty()) {
			auto [_, u] = q.top();
			q.pop();
			for (auto [v, w] : adj[u]) {
				if ((v == t || hot[v] <= mid) && dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					q.emplace(dis[v], v);
				}
			}
		}
		return dis[t] == min;
	};
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	std::cout << res << "\n";
	return 0;
} 
