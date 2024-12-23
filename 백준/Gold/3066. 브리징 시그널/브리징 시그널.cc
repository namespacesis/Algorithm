#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int T;
int N;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> arr;
        
        int n;
        cin >> n;
        arr.push_back(n);

        for (int i = 2; i <= N; i++) {
            cin >> n;
            if (arr.back() < n) {
				arr.push_back(n);
            }
            else {
                *lower_bound(arr.begin(), arr.end(), n) = n;
            }
        }

        int res = arr.size();

        cout << res << endl;
    }

    return 0;
}