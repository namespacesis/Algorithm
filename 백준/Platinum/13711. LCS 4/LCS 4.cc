#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N;
int arr[100001];

int main() {
    FastIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        arr[n] = i;
    }

    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        v[i] = arr[n];
    }

    vector<int> lis;
    lis.push_back(v[1]);

    for (int i = 2; i <= N; i++) {
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
			*it = v[i];
        }
    }

    int res = lis.size();

    cout << res << endl;

    return 0;
}