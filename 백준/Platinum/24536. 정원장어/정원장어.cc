#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N;
string dir;
int arr[300001];

int main() {
    FastIO;

    cin >> N;

    cin >> dir;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<int> leftLis(N + 1);
    vector<int> rightLis(N + 2);

    vector<int> tempLis;

    for (int i = 1; i <= N; i++) {
        if (dir[i - 1] == 'L') {
            if (tempLis.empty()) {
				tempLis.push_back(arr[i]);
			}

			if (tempLis.back() < arr[i]) {
				tempLis.push_back(arr[i]);
			} else {
				auto it = lower_bound(tempLis.begin(), tempLis.end(), arr[i]);
				*it = arr[i];
			}
        }

        leftLis[i] = tempLis.size();
    }

    tempLis.clear();

    for (int i = N; i >= 1; i--) {
        if (dir[i - 1] == 'R') {
            if (tempLis.empty()) {
                tempLis.push_back(arr[i]);
            }

            if (tempLis.back() < arr[i]) {
                tempLis.push_back(arr[i]);
            }
            else {
                auto it = lower_bound(tempLis.begin(), tempLis.end(), arr[i]);
                *it = arr[i];
            }
        }

        rightLis[i] = tempLis.size();
    }

    int maxVal = 0;

    for (int i = 0; i <= N; i++) {
        maxVal = max(maxVal, leftLis[i] + rightLis[i + 1]);
    }

    int res = N - maxVal;

    cout << res << endl;

    return 0;
}