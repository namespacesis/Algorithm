#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string A, B;
int pi[100000];

void getPi() {
    int m = A.size();
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && A[i] != A[j]) {
            j = pi[j - 1];
        }

        if (A[i] == A[j]) {
            pi[i] = ++j;
        }
    }
}

int kmp() {
    int n = B.size();
    int m = A.size();
    int j = 0;
    
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && B[i] != A[j]) {
            j = pi[j - 1];
        }

        if (B[i] == A[j]) {
			if (j == m - 1) {
				cnt++;
				j = pi[j];
			}
            else {
				j++;
			}
		}
    }

    return cnt;
}

int main() {
    FastIO;

    cin >> A >> B;

    B += B;

    B.pop_back();
    
    getPi();

    int res = kmp();

    cout << res << "\n";

    return 0;
}
