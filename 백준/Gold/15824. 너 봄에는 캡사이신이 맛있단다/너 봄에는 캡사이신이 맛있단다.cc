#include <iostream>
#include <algorithm>
#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007

using namespace std;
typedef long long ll;

int N;
ll arr[300000];

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    FastIO;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    ll res = 0;

    for (int i = 0; i < N; i++) {
        ll pos_contribution = (arr[i] * mod_pow(2, i, MOD)) % MOD;
        ll neg_contribution = (arr[i] * mod_pow(2, N - 1 - i, MOD)) % MOD;
        res = (res + pos_contribution - neg_contribution) % MOD;
    }

    if (res < 0) res += MOD;

    cout << res << "\n";

    return 0;
}
