#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N;
int minV = 1001;
int maxV = 0;

int main() {
    FastIO;

	cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        minV = min(minV, n);
        maxV = max(maxV, n);
    }

    int res = maxV - minV;

    cout << res << endl;

    return 0;
}
