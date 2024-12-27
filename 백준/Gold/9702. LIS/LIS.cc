#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int T;
int N;
int arr[500];

int main() {
    FastIO;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int res = 0;

        for (int i = 0; i < N; i++) {
            vector<int> v;
            v.push_back(arr[i]);
            res++;
            for (int j = i + 1; j < N; j++) {
                if (v.back() < arr[j]) {
                    v.push_back(arr[j]);
                }
                else {
                    auto it = lower_bound(v.begin(), v.end(), arr[j]);
                    *it = arr[j];
                }
                res += v.size();
            }
        }

        cout << "Case #" << tc << ": " << res << endl;
    }

    return 0;
}