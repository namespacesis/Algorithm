#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N, X;
int arr[100000];

static bool check(int mid) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < mid; i++) {
        pq.push(arr[i]);
    }

    for (int i = mid; i < N; i++) {
		int top = pq.top();
		pq.pop();

		if (top + arr[i] > X) {
			return false;
		}

		pq.push(top + arr[i]);
	}

    return true;
}

int main() {
    FastIO;

    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = N;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}
