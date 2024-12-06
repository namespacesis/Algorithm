#include <iostream>
#include <map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
int Q;
int l2r[1000001];
int r2l[1000001];
map<pair<int, int>, bool> um;

int main() {
    FastIO;

    cin >> N;

    fill(r2l, r2l + 1000001, 1e9);

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;

        l2r[l] = max(r, l2r[l]);
        r2l[r] = min(l, r2l[r]);
        
        um[{l, r}] = true;
    }
    
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        if (um.find({l, r}) != um.end()) {
            cout << 1 << endl;
            continue;
        }

        if (l2r[l] >= r && r2l[r] <= l) {
            cout << 2 << endl;
            continue;
        }

        cout << -1 << endl;
    }

    return 0;
}
