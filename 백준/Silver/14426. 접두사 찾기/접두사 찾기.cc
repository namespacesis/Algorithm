#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, M;
vector<string> arr;

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        arr.push_back(str);
    }

    sort(arr.begin(), arr.end());

    int res = 0;

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        int left = 0;
        int right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] < str) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            if (arr[mid].substr(0, str.size()) == str) {
                res++;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}