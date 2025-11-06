#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int T;
int K;
int arr[501];
int prefixSum[501];
int dp[501][501];

int main() {
	FastIO;

	cin >> T;

	while (T--) {
		cin >> K;

		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			prefixSum[i] = prefixSum[i - 1] + arr[i];
		}

		for (int len = 2; len <= K; len++) { 
            for (int i = 1; i <= K - len + 1; i++) {
                int j = i + len - 1; 

                dp[i][j] = 1e9;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }

                dp[i][j] += prefixSum[j] - prefixSum[i - 1];
            }
        }

        cout << dp[1][K] << endl;
	}

	return 0;
}