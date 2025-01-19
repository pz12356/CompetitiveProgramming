#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 R;
	std::cin >> R;

	i64 ans = 0;
	for (double x = -R + 0.5; x <= -0.5; x++) {
		double s = sqrt(R * R - x * x);
		i64 t = s - 0.5;
		ans += t * 2;
		if (s >= 0.5) ans++;
	}

	for (double x = 1.5; x <= R - 0.5; x++) {
		double s = sqrt(R * R - x * x);
		i64 t = s - 0.5;
		ans += t * 2;
		if (s >= 0.5) ans++;
	}
	std::cout << ans << "\n";
	return 0;
}