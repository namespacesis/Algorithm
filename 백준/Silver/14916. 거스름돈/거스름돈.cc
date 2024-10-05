#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int dp[100001];

int main() {
    FastIO;

    cin >> N;

    dp[2] = 1;
    dp[5] = 1;
    
	for (int i = 2; i <= N; i++) {
		if (dp[i - 2] != 0) {
			dp[i] = dp[i - 2] + 1;
		}
		if (i >= 5 && dp[i - 5] != 0) {
			if (dp[i] == 0) {
				dp[i] = dp[i - 5] + 1;
			}
			else {
				dp[i] = min(dp[i], dp[i - 5] + 1);
			}
		}
	}

	int res = dp[N];

	res == 0 ? cout << -1 << "\n" : cout << res << "\n";

	return 0;
}
