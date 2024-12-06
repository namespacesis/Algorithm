#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N, K;

int solve(int n) {
    int cnt = 0;

    while (n > 0) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }

    return cnt;
}

int main() {
    FastIO;

    cin >> N >> K;

    int res = 0;

    if (N <= K) {
        cout << res << endl;
        return 0;
    }

    while (true) {
        int cnt = solve(N);

        if (cnt <= K) break;

        res++;
        N++;
    }

    cout << res << endl;

    return 0;
}
