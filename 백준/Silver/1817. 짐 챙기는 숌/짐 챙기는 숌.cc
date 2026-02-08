#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;

int main() {
    FastIO;

    cin >> N >> M;

    int w;
    int tmp = M;
    int res;

    N == 0 ? res = 0 : res = 1;

    for (int i = 0; i < N; ++i) {
        cin >> w;
        tmp -= w;
        if (tmp < 0) {
            tmp = M - w;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}