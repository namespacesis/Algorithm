#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;

int main() {
    FastIO;

    cin >> N;

    int res = 0;
    int tmp = 0;
    int a;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a >= tmp) {
            res++;
        }
        tmp = a;
    }

    cout << res << endl;

    return 0;
}