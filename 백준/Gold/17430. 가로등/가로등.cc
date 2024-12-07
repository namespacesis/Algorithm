#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int T;
int N;
map<int, vector<int>> m;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        m.clear();
        cin >> N;

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;

            m[x].push_back(y);
        }

        for (auto& i : m) {
            sort(i.second.begin(), i.second.end());
        }

        bool flag = false;

        for (auto& i : m) {
            if (flag) break;
            for (auto& j : m) {
                if (i.first == j.first) continue;

                if (i.second != j.second) {
                    flag = true;
                    break;
                }
            }
        }

        string res = "";
        flag ? res = "NOT BALANCED" : res = "BALANCED";

        cout << res << endl;
    }

    return 0;
}
