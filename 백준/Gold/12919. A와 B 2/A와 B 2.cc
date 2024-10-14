#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

bool dfs(string S, string T) {
    if (S == T) return true;
    if (S.size() >= T.size()) return false;

    if (T.back() == 'A') {
        if (dfs(S, T.substr(0, T.size() - 1))) return true;
    }

    if (T.front() == 'B') {
        string reversedT = T;
        reverse(reversedT.begin(), reversedT.end());
        if (dfs(S, reversedT.substr(0, reversedT.size() - 1))) return true;
    }

    return false;
}

int main() {
    FastIO;

    string S;
    string T;

    cin >> S >> T;

    cout << (dfs(S, T) ? 1 : 0) << "\n";

    return 0;
}