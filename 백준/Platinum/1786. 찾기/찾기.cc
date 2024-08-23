#include <iostream>
#include <string>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string T, P;
int pi[1000000];
int cnt = 0;
vector<int> res;

void kmp() {
    int n = T.size();
    int m = P.size();
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }
        if (P[i] == P[j]) {
			pi[i] = ++j;
		}
    }

    j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }
        if (T[i] == P[j]) {
            if (j == m - 1) {
                cnt++;
                res.push_back(i - m + 2);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
}

int main() {
    FastIO;

    getline(cin, T);
    getline(cin, P);

    kmp();

    cout << cnt << "\n";
    for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

    return 0;
}
