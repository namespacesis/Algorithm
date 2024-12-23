#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int T;
int N;
int arr[40001];

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        
        vector<int> cnt;
        cnt.push_back(arr[1]);

        for (int i = 2; i <= N; i++) {
            if (cnt.back() < arr[i]) {
				cnt.push_back(arr[i]);
            }
            else {
                *lower_bound(cnt.begin(), cnt.end(), arr[i]) = arr[i];
            }
        }

        int res = cnt.size();

        cout << res << endl;
    }

    return 0;
}