#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int T;
int k;
string arr[100];

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        string res = "0";

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                string s = arr[i] + arr[j];

                string s_rev = s;
                reverse(s_rev.begin(), s_rev.end());

                if (s == s_rev) {
                    res = s;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
