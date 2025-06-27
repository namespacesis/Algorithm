#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int N;

int main() {
    FastIO;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);

        s[0] = toupper(s[0]);

        cout << s << endl;
    }
}