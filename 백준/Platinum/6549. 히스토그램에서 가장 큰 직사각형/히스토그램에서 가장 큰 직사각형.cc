#include <iostream>
#include <stack>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int arr[100000];

int main() {
    FastIO;

    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        stack<int> s;
        int idx = 0;

        long long res = 0;

        while (idx < N) {
            if (s.empty() || arr[s.top()] <= arr[idx]) {
                s.push(idx++);
            }
            else {
                int top = s.top();
                s.pop();

                long long area = (long long)arr[top] * (s.empty() ? idx : idx - s.top() - 1);
                res = max(res, area);
            }
        }

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            long long area = (long long)arr[top] * (s.empty() ? idx : idx - s.top() - 1);
            res = max(res, area);
        }

        cout << res << "\n";
    }

    return 0;
}
