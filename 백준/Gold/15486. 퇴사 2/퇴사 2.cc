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
int dp[1500001];

int main() {
	FastIO;

	cin >> N;

    for (int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        arr[i] = { t, p };
    }

    for (int i = N - 1; i >= 0; i--) {
        Info info = arr[i];
        if (i + info.t <= N) {
            dp[i] = max(info.p + dp[i + info.t], dp[i + 1]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    int res = dp[0];

    cout << res << endl;

    return 0;
}