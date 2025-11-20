#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;
int M;
int dp[41];
bool check[41];

int main() {
	FastIO;

	cin >> N >> M;

    int num;
    for (int i = 0; i < M; i++) {
        cin >> num;
        check[num] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int res = 1;

    int tmp = 0;
    
    for (int i = 1; i <= N; i++) {
        if (check[i]) {
            res *= dp[tmp];
            tmp = 0;
        }
        else {
            tmp++;
        }
    }

    res *= dp[tmp];

    cout << res << endl;

    return 0;
}