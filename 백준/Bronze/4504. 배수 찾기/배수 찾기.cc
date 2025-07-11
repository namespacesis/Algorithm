#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int n, a;
string r1 = " is NOT a multiple of ";
string r2 = " is a multiple of ";

int main() {
    FastIO;

    cin >> n;

    while(true) {
        cin >> a;
        if (a == 0) return 0;
        
        if (a % n == 0) {
            cout << a << r2 << n << "." << endl;
        }
        else {
            cout << a << r1 << n << "." << endl;
        }
    }
}