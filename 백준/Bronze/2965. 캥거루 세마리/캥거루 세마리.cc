#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int A, B, C;

int main() {
    FastIO;

    cin >> A >> B >> C;

    int n1 = B - A - 1;
    int n2 = C - B - 1;

    int res = max(n1, n2);

    cout << res << endl;

    return 0;
}