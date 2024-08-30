#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MAX_VALUE 360000

using namespace std;

int N;
int S[MAX_VALUE * 2];
int T[MAX_VALUE];
int pi[360000];

void getPi() {
    int m = MAX_VALUE;

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && T[i] != T[j]) {
            j = pi[j - 1];
        }
        if (T[i] == T[j]) {
            pi[i] = ++j;
        }
    }
}

bool kmp() {
    int n = MAX_VALUE * 2;
    int m = MAX_VALUE;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && S[i] != T[j]) {
            j = pi[j - 1];
        }
        if (S[i] == T[j]) {
            if (j == m - 1) {
                return true;
            }
            else {
                j++;
            }
        }
    }

    return false;
}

int main() {
    FastIO;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        S[v] = 1;
        S[v + MAX_VALUE] = 1;
    }

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        T[v] = 1;
    }

    getPi();

    bool res = kmp();

    cout << (res ? "possible" : "impossible") << "\n";

    return 0;
}
