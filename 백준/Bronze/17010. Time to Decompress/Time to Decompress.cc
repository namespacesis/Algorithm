#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int L;
int n;
char c;

int main() {
    FastIO;

    cin >> L;

    while(L--) {
        cin >> n >> c;

        string s = "";
        while (n--) {
            s += c;
        }

        cout << s << endl;
    }

    return 0;
}