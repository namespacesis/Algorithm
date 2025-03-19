#include <iostream>
#include <string>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

string s;
string ans = "UCPC";

int main() {
    FastIO;

    getline(cin, s);

    int idx = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ans[idx]) {
            idx++;
        }

        if (idx == 4) {
            break;
        }
    }

    string res;

    idx == 4 ? res = "I love UCPC" : res = "I hate UCPC";

    cout << res << endl;

    return 0;
}
