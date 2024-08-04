#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::vector<int> num;
	std::sort(a.begin(), a.end());
	do {
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = res * 10 + a[i];
		}
		num.push_back(res);
	} while (std::next_permutation(a.begin(), a.end()));
	
	int m = num.size();
	
	auto get = [&](std::vector<int>& v) {
		int res = 0;
		for (int x : v) {
			res += x * x;
		}
		return res;
	};
	for (int s = 0; s < (1 << m); s++) {
		if (__builtin_popcount(s) == m / 2) {
			std::vector<int> x, y;
			for (int i = 0; i < m; i++) {
				if (s >> i & 1) {
					x.push_back(num[i]);
				} else {
					y.push_back(num[i]);
				}
			}
			if (get(x) == get(y)) {
				for (auto val : x) {
					std::cout << val << "\n";
				}
				exit(0);
			}
		}
	}
	return 0;
} 
