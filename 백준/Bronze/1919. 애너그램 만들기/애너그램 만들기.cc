#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int main() {
    FastIO;

    string s1;
    string s2;

    bool visited[1000] = {false,};

    cin >> s1 >> s2;

    int res = s1.size() + s2.size();

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j] && !visited[j]) {
                visited[j] = true;
                res -= 2;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}