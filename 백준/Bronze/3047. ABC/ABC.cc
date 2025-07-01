#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int A, B, C;

int main() {
    FastIO;

    cin >> A >> B >> C;

    vector<int> v = {A, B, C};
    sort(v.begin(), v.end());

    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') cout << v[0] << " ";
        else if (s[i] == 'B') cout << v[1] << " ";
        else if (s[i] == 'C') cout << v[2] << " ";
    }
    cout << endl;

    return 0;
}