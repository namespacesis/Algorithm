#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
string P;
string T;
int pi[1000001];
int res = 0;

void getPi() {
    int j = 0;

    for (int i = 1; i < N; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }

        if (P[i] == P[j]) {
            pi[i] = ++j;
        }
    }
}

void kmp() {
    int j = 0;

    for (int i = 0; i < N * 2 - 1; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }

        if (T[i] == P[j]) {
            if (j == N - 1) {
                res++;
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        char t;
        cin >> t;
        P += t;
    }

    for (int i = 0; i < N; i++) {
        char t;
        cin >> t;
        T += t;
    }

    T += T;
    T.pop_back();

    getPi();
    kmp();

    int g = gcd(res, N);

    cout << res / g << "/" << N / g << "\n";
    
    return 0;
}
