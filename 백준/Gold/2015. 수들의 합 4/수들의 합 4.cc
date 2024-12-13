#include <iostream>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N, K;
ll arr[200001];
unordered_map<int, int> um;

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        ll n;
        cin >> n;

        arr[i] = arr[i - 1] + n;
    }

    ll res = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] == K) res++;

        res += um[arr[i] - K];
        um[arr[i]]++;
    }

    cout << res << endl;

    return 0;
}
