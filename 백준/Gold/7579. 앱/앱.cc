#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int bite[101];
int cost[101];
int dp[101][10001];
int total;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> bite[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		total += cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= total; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= total; i++) {
		if (dp[N][i] >= M) {
			cout << i << "\n";
			return 0;
		}
	}
}