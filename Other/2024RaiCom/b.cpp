#include <bits/stdc++.h>

int RankScore(int x) {
	if (x == 1) 
		return 12;
	if (x == 2) 
		return 9;
	if (x == 3)
		return 7;
	if (x == 4)
		return 5;
	if (x == 5)
		return 4;
	if (x >= 6 && x <= 7) 
		return 3;
	if (x >= 8 && x <= 10) 
		return 2;
	if (x >= 11 && x <= 15) 
		return 1;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> score(21);
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 20; j++) {
			int p, k;
			std::cin >> p >> k;
			
			score[j] += k + RankScore(p);
		}
	}
	
	for (int i = 1; i <= 20; i++) {
		std::cout << i << " " << score[i] << "\n";
	}
	return 0;
}
