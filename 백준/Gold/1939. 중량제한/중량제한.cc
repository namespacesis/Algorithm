#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
} arr[100001];

int N, M;
int F1, F2;
int parent[100001];

int getParent(int x) {
    if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int S, E, W;
        cin >> S >> E >> W;

        arr[i].from = S;
        arr[i].to = E;
        arr[i].weight = W;
    }

    sort(arr, arr + M);

    cin >> F1 >> F2;

    for (int i = 0; i < M; i++) {
        int a = arr[i].from;
        int b = arr[i].to;

        unionParent(a, b);

        if (getParent(F1) == getParent(F2)) {
			cout << arr[i].weight << "\n";
			break;
		}
    }

    return 0;
}
