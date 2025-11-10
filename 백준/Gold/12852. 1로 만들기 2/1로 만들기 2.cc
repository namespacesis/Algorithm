#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

const int MAX_N = 1000001;
int N;
int dp[MAX_N];
int trace[MAX_N];

int main() {
	FastIO;

	cin >> N;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        trace[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            trace[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            trace[i] = i / 3;
        }
    }

    cout << dp[N] << endl;

    cout << N << " ";

    int cur = N;

    while (cur != 1) {
        cur = trace[cur];
        cout << cur << " ";
    }

    return 0;
}