#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
int Q;
unordered_map<int, int> l2r;
unordered_map<int, int> r2l;
map<pair<int, int>, bool> um;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;

        l2r[l] = max(r, l2r[l]);
        if (r2l.find(r) == r2l.end()) {
            r2l[r] = l;
        }
        else {
            r2l[r] = min(r2l[r], l);
        }
        
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

        if (l2r.find(l) == l2r.end() || r2l.find(r) == r2l.end()) {
			cout << -1 << endl;
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
