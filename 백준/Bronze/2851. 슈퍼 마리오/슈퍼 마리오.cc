#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int main() {
    FastIO;

    int n;
    int sum = 0;
    int diff = 100;
    int res = 0;

    for (int i = 0; i < 10; i++) {
        cin >> n;

        sum += n;

        if (abs(100 - sum) <= diff) {
            res = sum;
            diff = abs(100 - sum);
        }
        else {
            continue;
        }
    }

    cout << res << endl;

    return 0;
}