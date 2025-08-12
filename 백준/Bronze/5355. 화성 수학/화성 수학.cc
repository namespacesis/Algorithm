#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int T;

int main() {
    FastIO;

    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);
        
        stringstream ss(s);

        double n;    
        ss >> n;

        char c;
        while (ss >> c) {
            if (c == '@') {
                n *= 3;
            }
            else if (c == '%') {
                n += 5;
            }
            else if (c == '#') {
                n -= 7;
            }
        }
        
        cout << fixed;
        cout.precision(2);
        cout << n << endl;
    }

    return 0;
}