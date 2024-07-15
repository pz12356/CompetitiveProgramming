#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, w;
	std::cin >> n >> w;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++, w++) {
		if (w == 8) w = 1;
		if (w == 4) {
			if (a[i] >= 35) ans2++;
			continue;
		}
		if (a[i] >= 35) {
			ans1++;
		}
	}
	std::cout << ans1 << " " << ans2 << "\n";
}
