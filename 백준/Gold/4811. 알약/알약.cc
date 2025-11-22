#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
ll dp[31][31];

void makeTable() {
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (i > j) continue;
            if (i == 0) dp[j][i] = 1;
            else dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
    }
}

int main() {
	FastIO;

    makeTable();

	while (true) {
        cin >> N;

        if (N == 0) break;

        cout << dp[N][N] << endl;
    }

    return 0;
}