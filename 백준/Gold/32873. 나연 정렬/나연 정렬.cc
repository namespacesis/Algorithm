#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N;

int main() {
    FastIO;

    cin >> N;

    vector<int> v;
    v.reserve(N);

    int a;
    cin >> a;
    v.push_back(a);

    for (int i = 1; i < N; i++) {
        cin >> a;

        if (v.back() < a) {
            v.push_back(a);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), a);
            *it = a;
        }
    }

    int res = v.size();

    cout << res << endl;

    return 0;
}