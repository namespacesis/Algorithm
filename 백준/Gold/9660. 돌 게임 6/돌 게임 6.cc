#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

ll N;

int main() {
    FastIO;

    cin >> N;

    string res;

    (N % 7 == 2) or (N % 7 == 0) ? res = "CY" : res = "SK";

    cout << res << endl;

    return 0;
}