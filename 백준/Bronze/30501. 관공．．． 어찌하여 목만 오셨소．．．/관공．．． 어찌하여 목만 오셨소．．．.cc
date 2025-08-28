#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int main() {
    FastIO;

    int N;

    cin >> N;

    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.find('S') != string::npos) {
            cout << s << endl;
        }
    }

    return 0;
}