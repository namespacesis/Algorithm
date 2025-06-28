#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int T;
int N;
int C;
double G;

int main() {
    FastIO;

    cin >> T;

    cout << fixed;
    cout.precision(1);

    while (T--) {
        cin >> N;

        int tC = 0;
        double tG = 0;
        for (int i = 0; i < N; i++) {
            cin >> C >> G;

            tC += C;
            tG += G * C;
        }

        tG /= tC;

        cout << tC << " " << tG << endl;
    }

    return 0;
}