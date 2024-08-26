#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string S;
int K;
int pi[500000];

void getPi() {
    int m = S.size();
    int j = 0;

    for (int i = 1; i < m; i++) {
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
    
    cin >> S >> K;

    getPi();

    int m = S.size();

    long long res;

    res = (long long)K * m - (long long)(K - 1) * pi[m - 1];

    cout << res << "\n";

    return 0;
}
