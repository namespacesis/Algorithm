#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N, mp[500001], pos[100001];
pair<int, int> a[100001];
set<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
        ans.insert(a[i].first);
    }

    sort(a, a + N);
    for (int i = 0; i < N; i++) {
        mp[a[i].second] = i;
    }

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
        if (v.size() == idx) v.push_back(a[i].second);
        else v[idx] = a[i].second;
        pos[i] = idx;
    }
    int k = v.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (pos[i] == k) {
            ans.erase(a[i].first);
            if (--k < 0) break;
        }
    }
    cout << ans.size() << "\n";
    for (auto k : ans) cout << k << "\n";
}
