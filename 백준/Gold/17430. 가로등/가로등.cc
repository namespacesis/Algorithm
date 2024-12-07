#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <functional>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int x : v) {
            hash ^= hash * 31 + hash + x;
        }
        return hash;
    }
};

struct VectorEqual {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return v1 == v2;
    }
};

int T;
int N;
map<int, vector<int>> m;
unordered_set<vector<int>, VectorHash, VectorEqual> us;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;

            m[x].push_back(y);
        }

        for (auto& i : m) {
            sort(i.second.begin(), i.second.end());
            us.insert(i.second);
        }

        string res = "";
        us.size() == 1 ? res = "BALANCED" : res = "NOT BALANCED";

        cout << res << endl;

        m.clear();
        us.clear();
    }

    return 0;
}
