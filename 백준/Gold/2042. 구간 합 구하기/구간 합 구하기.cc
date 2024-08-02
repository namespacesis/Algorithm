#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M, K;
long long arr[1000001];
long long tree[4000004];

long long init(int start, int end, long long node) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, long long node, int idx, long long diff) {
	if (idx < start || end < idx) return;

	tree[node] += diff;

	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

long long sum(int start, int end, long long node, int left, int right) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    FastIO;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

	init(0, N - 1, 1);

    long long a, b, c;

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
			update(0, N - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
        }
        else {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
        }
    }
    
	return 0;
}
