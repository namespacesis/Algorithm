#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int T;
int c, v;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> c >> v;

        int r1 = c / v;
        int r2 = c % v;

        cout << "You get " << r1 << " piece(s) and your dad gets " << r2 << " piece(s)." << endl;
    }

    return 0;
}