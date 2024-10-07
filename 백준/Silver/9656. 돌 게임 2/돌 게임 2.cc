#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int dp[1001];

int main() {
    FastIO;

    cin >> N;

    dp[1] = 2;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= N; i++) {
        if (dp[i - 1] == 2 || dp[i - 3] == 2) {
            dp[i] = 1;
        }
        else {
            dp[i] = 2;
        }
    }

    dp[N] == 1 ? cout << "SK" : cout << "CY";

    return 0;
}
