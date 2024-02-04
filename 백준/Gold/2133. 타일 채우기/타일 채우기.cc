#include <iostream>

using namespace std;

int N;
int dp[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int n = 3; n <= N; n++) {
        if (n % 2 != 0) {
            dp[n] = 0;
        }
        else {
            for (int i = 2; i <= N; i += 2) {
                if (i == 2) dp[n] = dp[n - i] * dp[2];
                else if ((n - i) >= 0) dp[n] += dp[n - i] * 2;
            }
        }
    }
    cout << dp[N] << "\n";
    return 0;
}