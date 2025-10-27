#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;

int main() {
    FastIO;

    cin >> N;

    int res = 0;

    for (int i = 1; i <= N; i++) {
        string s = to_string(i);
        int v = 0;
        for (int j = 0; j < s.size(); j++) {
            v += (s[j] - '0');
        }
        if (i % v == 0) {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
