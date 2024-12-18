#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int T;
int arr[4][2];
vector<long long> v;

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        v.clear();

        for (int i = 0; i < 4; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                int x = arr[i][0] - arr[j][0];
                int y = arr[i][1] - arr[j][1];
                v.push_back((long long)x * x + (long long)y * y);
            }
        }

        sort(v.begin(), v.end());

        if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}
