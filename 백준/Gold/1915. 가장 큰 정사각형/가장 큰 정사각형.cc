#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;
int N, M;
int arr[MAXN][MAXM];
int dp[MAXN][MAXM];

int findMinValue(int x, int y) {
    int ret = 1e9;

    ret = min(ret, dp[x - 1][y]);
    ret = min(ret, dp[x - 1][y - 1]);
    ret = min(ret, dp[x][y - 1]);

    return ret;
}

int main() {
	FastIO;

	cin >> N >> M;

    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) continue;

            dp[i][j] = 1;

            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] += findMinValue(i, j);
            }

            res = max(res, dp[i][j]);
        }
    }

    cout << res * res << endl;

    return 0;
}