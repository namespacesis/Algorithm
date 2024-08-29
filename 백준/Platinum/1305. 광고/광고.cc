#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int L;
string S;
int pi[1000000];

void getPi() {
    int m = S.size();

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && S[i] != S[j]) {
            j = pi[j - 1];
        }
        if (S[i] == S[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    FastIO;
    
    cin >> L >> S;

    getPi();

    int res = L - pi[L - 1];

    cout << res << "\n";

    return 0;
}
