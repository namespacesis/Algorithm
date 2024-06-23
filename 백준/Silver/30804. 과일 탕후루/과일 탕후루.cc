#include <iostream>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N;
int arr[200000];
int fruit[10];

bool checkCnt() {
    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        if (fruit[i] > 0) {
            cnt++;
        }
        
        if (cnt > 2) {
            return false;
        }
    }

    return true;
}

int twoPointer() {
    int left = 0;
    int right = 0;
    int res = 0;

    while (left < N) {
        while (right < N) {
            fruit[arr[right++]]++;

            if (!checkCnt()) {
                right--;
                fruit[arr[right]]--;

                break;
            }
        }

        res = max(res, right - left);

        fruit[arr[left++]]--;
    }

    return res;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int res = twoPointer();

    cout << res << "\n";

    return 0;
}
