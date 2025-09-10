#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

ll N, P, Q;
unordered_map<ll, ll> um;
ll res;

ll calc(ll num) {
    ll ret;

    if (um.find(num) != um.end()) {
        return um[num];
    }

    ret = calc(num/P) + calc(num/Q);
    um[num] = ret;

    return ret;
}

int main() {
    FastIO;

    cin >> N >> P >> Q;

    um[0] = 1;

    if (N == 0) res = 1;
    else {
        res = calc(N/P) + calc(N/Q);
    }

    cout << res << endl;

    return 0;
}