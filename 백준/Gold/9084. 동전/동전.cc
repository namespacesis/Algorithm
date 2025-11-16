#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int T;
int N;
int M;
int arr[20];
int dp[10001];

int main() {
	FastIO;

	cin >> T;

    while (T--) {
        memset(dp, 0, sizeof(dp));
        
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        cin >> M;

        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = arr[i]; j <= M; j++) {
                dp[j] += dp[j - arr[i]];
            }
        }

        cout << dp[M] << endl;
    }

    return 0;
}