#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int L, P, V;
int res;

int main() {
    FastIO;

    int n = 0;

    while(true) {
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) {
            break;
        }

        res = (V / P) * L + min(L, V % P);

        cout << "Case " << ++n << ": " << res << endl;
    }

    return 0;
}