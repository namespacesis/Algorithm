#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int N;

int main() {
    FastIO;

    cin >> N;

    int cnt = 8 * (N - 1);

    int n;

    while (N--) {
        cin >> n;
        cnt += n;
    }

    cout << cnt / 24 << " " << cnt % 24 << endl;

    return 0;
}