#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

const int MAX_N = 10001;
int T;
int N;
int dp[MAX_N][4];

void makeTable() {
    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;
    
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i < MAX_N; i++) {
        dp[i][1] = 1;

        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];

        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

int main() {
	FastIO;

	cin >> T;

    makeTable();

    while (T--) {
        cin >> N;

        int res = dp[N][1] + dp[N][2] + dp[N][3];

        cout << res << endl;
    }

    return 0;
}