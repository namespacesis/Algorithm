#include <iostream>
#include <string>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

unordered_map<string, int> um;
unordered_map<string, bool> check;

int main() {
    FastIO;

    string S, E, Q;

    cin >> S >> E >> Q;

    int res = 0;

    string T, N;

    while (cin >> T >> N) {
        if (T <= S) {
            um[N]++;
        }
        else if (T >= E && T <= Q) {
            if (um.find(N) != um.end() && !check[N]) {
                res++;
                check[N] = true;
            }
        }
		else if (T > Q) {
			break;
		}
    }

    cout << res << "\n";

    return 0;
}
