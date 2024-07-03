#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N;
int arr[4000][4];
vector<int> v1, v2;
long long answer = 0;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v1.push_back(arr[i][0] + arr[j][1]);
            v2.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++) {
		int low = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();

		answer += high - low;
	}

    cout << answer << "\n";
    return 0;
}