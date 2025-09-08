#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int N, h;
int res[500000];
stack<pair<int, int>> s;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h;

        if (s.empty()) {
            s.push({i + 1, h});
            res[i] = 0;
        }
        else {
            while (true) {
                if (s.top().second >= h) {
                    res[i] = s.top().first;
                    break;
                }
                else {
                    s.pop();
                    if (s.empty()) {
                        res[i] = 0;
                        break;
                    }
                }
            }
            s.push({i + 1, h});
        }
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}