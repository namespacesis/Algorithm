#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n;
string str;
bool palindrome[2501][2501];
int cache[2501];

int solve(int end) {
	if (end == -1) return 0;
	if (end == 0) return 1;
	int& ret = cache[end];
	if (ret != -1) return ret;
	int ans = 987654321;
	for (int i = 0; i <= end; i++) {
		if (palindrome[i][end]) ans = min(ans, solve(i - 1) + 1);
	}
	return ret = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	n = str.length();
	memset(cache, -1, sizeof(cache));
	memset(palindrome, false, sizeof(palindrome));

	for (int i = 0; i < n; i++) palindrome[i][i] = true;
	for (int i = 0; i < n - 1; i++)
		if (str[i] == str[i + 1]) palindrome[i][i + 1] = true;
	for (int i = 3; i <= n; i++) {
		for (int s = 0; s < n; s++) {
			if (s + i > n) break;
			int e = s + i - 1;
			if (str[s] == str[e] && palindrome[s + 1][e - 1]) palindrome[s][e] = true;
		}
	}

	cout << solve(str.length() - 1) << '\n';
}