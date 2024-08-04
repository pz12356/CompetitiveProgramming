#include <bits/stdc++.h>

using i64 = long long;

bool isValid(char c) {
	return std::isalpha(c) || std::isdigit(c);
}

int cal(std::string s) {
	int a = 0, b = 0, x = 0;
	for (char c : s) {
		a += c >= 'a' && c <= 'z';
		b += c >= 'A' && c <= 'Z';
		x += c >= '0' && c <= '9';
	}
	
	if (a > 0 && b > 0 && x > 0) {
		return 5;
	} else if ((a > 0 && x > 0) || (b > 0 && x > 0)) {
		return 3;
	} else if (a > 0 && b > 0) {
		return 1;
	}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	int score = 0, len = 0, cnt = 0;
	while(std::cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (not isValid(s[i])) {
				continue;
			}
			int j = i;
			while (j < s.length() && isValid(s[j])) j++;
			score += cal(s.substr(i, j - i));
			len += j - i;
			i = j - 1;
			cnt++;
		}
	}
	std::cout << score << "\n" << len << " " << cnt << "\n";
	return 0;
} 
