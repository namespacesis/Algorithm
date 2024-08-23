#include <iostream>
#include <string>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string S;
int pi[1000001];
int res;

int main() {
    FastIO;

    while (true) {
        cin >> S;

        if (S[0] == '.') break;

        int len = S.size();
        memset(pi, 0, sizeof(pi));

        int j = 0;

        for (int i = 1; i < len; i++) {

            while (j > 0 && S[i] != S[j]) {
                j = pi[j - 1];
            }

            if (S[i] == S[j]) {
                pi[i] = ++j;
            }
        }

        res = len - pi[len - 1];

        if (len % res == 0) {
            cout << len / res << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }

    return 0;
}
