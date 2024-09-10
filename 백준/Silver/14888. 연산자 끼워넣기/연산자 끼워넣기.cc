#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int arr[11];
int res1 = -1000000000;
int res2 = 1000000000;

void dfs(int p, int m, int x, int d, int idx, int val) {
    if (idx == N - 1) {
        if (val > res1) res1 = val;
        if (val < res2) res2 = val;
    }
    
    if (p > 0) dfs(p - 1, m, x, d, idx + 1, val + arr[idx + 1]);
    if (m > 0) dfs(p, m - 1, x, d, idx + 1, val - arr[idx + 1]);
    if (x > 0) dfs(p, m, x - 1, d, idx + 1, val * arr[idx + 1]);
    if (d > 0) dfs(p, m, x, d - 1, idx + 1, val / arr[idx + 1]);
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int p, m, x, d;
    cin >> p >> m >> x >> d;

    dfs(p, m, x, d, 0, arr[0]);

    cout << res1 << "\n" << res2 << "\n";

    return 0;
}
