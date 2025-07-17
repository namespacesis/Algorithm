#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

string s;

int main() {
    FastIO;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s.substr(i, 2) == "pi") {
            i++;
        }
        else if (s.substr(i, 2) == "ka") {
            i++;
        }
        else if (s.substr(i, 3) == "chu") {
            i+=2;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}