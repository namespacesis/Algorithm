#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
int a[10001], b[10001], c[10002];
pair<int, int> trc[10001];

int main() {
    FastIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int v;
        cin >> v;
        a[v] = i;
    }

    for (int i = 1; i <= N; i++) cin >> b[i];

    for (int i = 1; i <= N; i++) c[a[b[i]]] = i;

    vector<int> v;

    for (int i = 1; i <= N; i++) {
        int j = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
        if (j < v.size()) {
            v[j] = c[i];
        }
        else {
            v.push_back(c[i]);
        }
        trc[i] = { j, c[i] };
    }

    int j = v.size() - 1;
    vector<int> l;
    for (int i = N; i > 0; i--) {
        if (trc[i].first == j) {
            l.push_back(trc[i].second);
            j--;
        }
    }

    cout << l.size() << endl;

    for (auto& p : l) p = b[p];
    sort(l.begin(), l.end());

    for (auto& p : l) cout << p << " ";
    cout << endl;

    return 0;
}