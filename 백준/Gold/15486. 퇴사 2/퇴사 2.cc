#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

struct Info {
    int t;
    int p;
};

int N;
Info arr[1500000];
int dp[1500001][2];

int main() {
	FastIO;

	cin >> N;

    for (int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        arr[i] = { t, p };
    }

    Info lastDay = arr[N - 1];

    if (lastDay.t == 1) {
        dp[N - 1][1] = lastDay.p;
    }

    for (int i = N - 2; i >= 0; i--) {
        Info info = arr[i];
        if (i + info.t <= N) {
            dp[i][1] = info.p + max(dp[i + info.t][0], dp[i + info.t][1]);
        }
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
    }

    int res = max(dp[0][0], dp[0][1]);

    cout << res << endl;

    return 0;
}