#include <iostream>
#include <string>
#include <regex>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;

int main() {
    FastIO;

    cin >> T;

    regex pattern("(100+1+|01)+");

    while (T--) {
        string s;
        cin >> s;

        string res = "NO";
        if (regex_match(s, pattern)) res = "YES";

        cout << res << "\n";
    }

    return 0;
}