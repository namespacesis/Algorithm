#include <iostream>
#include <cstring>

#define INT_MAX 1e9

using namespace std;

int T;
int N, W;
int arr[10001][2];
int dp[10001][5];

int simulate(int S, int N) {
	for (int i = S; i <= N; i++) {
		int res = INT_MAX;

		for (int j = 0; j < 5; j++) {
			res = min(res, dp[i - 1][j]);
		}

		dp[i][0] = res + 2;
		dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] = dp[i][0];

		if (arr[i - 1][0] + arr[i][0] <= W && arr[i - 1][1] + arr[i][1] <= W) {
			dp[i][3] = dp[i - 1][0];
		}

		if (arr[i - 1][0] + arr[i][0] <= W) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + 1;
		}

		if (arr[i - 1][1] + arr[i][1] <= W) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
		}

		if (arr[i][0] + arr[i][1] <= W) {
			dp[i][4] = res + 1;
		}
	}

	int ret = INT_MAX;

	for (int i = 0; i < 5; i++) {
		ret = min(ret, dp[N][i]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> W;

		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[j][i];
			}
		}

		int res = INT_MAX;

		if (N >= 2) {
			if (arr[1][0] + arr[N][0] <= W) {
				memset(dp, 0, sizeof(dp));
				dp[2][0] = 3;
				dp[2][1] = 3;
				dp[2][2] = 2 + !(arr[1][1] + arr[2][1] <= W);
				dp[2][3] = 3;
				dp[2][4] = 2 + !(arr[2][0] + arr[2][1] <= W);
				simulate(3, N);
				res = min(res, min(dp[N][0], dp[N][2]));
			}

			if (arr[1][1] + arr[N][1] <= W) {
				memset(dp, 0, sizeof(dp));
				dp[2][0] = 3;
				dp[2][1] = 2 + !(arr[1][0] + arr[2][0] <= W);
				dp[2][2] = 3;
				dp[2][3] = 3;
				dp[2][4] = 2 + !(arr[2][0] + arr[2][1] <= W);
				simulate(3, N);
				res = min(res, min(dp[N][0], dp[N][1]));
			}

			if (arr[1][0] + arr[N][0] <= W && arr[1][1] + arr[N][1] <= W) {
				memset(dp, 0, sizeof(dp));
				dp[2][0] = 2;
				dp[2][1] = 2;
				dp[2][2] = 2;
				dp[2][3] = 2;
				dp[2][4] = 1 + !(arr[2][0] + arr[2][1] <= W);
				res = min(res, simulate(3, N - 1) + 2);
			}
		}

		memset(dp, 0, sizeof(dp));
		dp[1][0] = 2;
		dp[1][1] = 2;
		dp[1][2] = 2;
		dp[1][3] = 2;
		dp[1][4] = 1 + !(arr[1][0] + arr[1][1] <= W);
		res = min(res, simulate(2, N));

		cout << res << "\n";
	}

	return 0;
}