#include <iostream>
#include <unordered_map>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int Q;
unordered_map<string, priority_queue<int>> um;

int main() {
    FastIO;

    cin >> Q;

    long long res = 0;

    while (Q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            string name;
            cin >> name;

            int k;
            cin >> k;

            for (int i = 0; i < k; i++) {
                int C;
                cin >> C;

                um[name].push(C);
            }
        }
        else {
            string name;
            cin >> name;

            int cnt;
            cin >> cnt;

            if (um.find(name) == um.end()) continue;
            
            while (!um[name].empty() && cnt) {
                cnt--;
                res += um[name].top();
                um[name].pop();
            }
        }
    }

    cout << res << endl;

    return 0;
}
