#include <iostream>
#include <map>
#include <cmath>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
map<int, int> left_trees;
map<int, int> right_trees;

int main() {
    FastIO;

    cin >> N;

    int idx = 0;
    long long res = 0;

    for (int i = 0; i < N; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int n;
            cin >> n;

            if (n < idx) {
                left_trees[-n]++;
            }
            else {
                right_trees[n]++;
            }
        }
        else if (q == 2) {
            while (!left_trees.empty() || !right_trees.empty()) {
                int left_distance = left_trees.empty() ? 1e9 : abs(-left_trees.begin()->first - idx);

                int right_distance = right_trees.empty() ? 1e9 : abs(right_trees.begin()->first - idx);

                if (left_distance <= right_distance) {
                    auto it = left_trees.begin();
                    int pos = -it->first;
                    res += abs(pos - idx);
                    idx = pos;

                    if (--it->second == 0) {
                        left_trees.erase(it);
                    }
                }
                else {
                    auto it = right_trees.begin();
                    int pos = it->first;
                    res += abs(pos - idx);
                    idx = pos;

                    if (--it->second == 0) {
                        right_trees.erase(it);
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
