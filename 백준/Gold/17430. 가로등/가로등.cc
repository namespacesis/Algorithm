#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int T;
int N;
map<int, vector<int>> m;
set<vector<int>> s;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        m.clear();
        s.clear();
        cin >> N;

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;

            m[x].push_back(y);
        }

        for (auto& i : m) {
            sort(i.second.begin(), i.second.end());
            s.insert(i.second);
        }

        string res = "";
        s.size() == 1 ? res = "BALANCED" : res = "NOT BALANCED";

        cout << res << endl;
    }

    return 0;
}
