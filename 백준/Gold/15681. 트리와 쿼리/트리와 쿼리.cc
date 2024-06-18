#include <iostream>
#include <vector>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N, R, Q;
vector<int> arr[100001];
vector<int> q;
vector<int> tree[100001];
int treeSize[100001];

void makeTree(int parent, int cur) {
	for (int i = 0; i < arr[cur].size(); i++) {
		int next = arr[cur][i];

		if (parent == next) continue;

		tree[cur].push_back(next);
		
		makeTree(cur, next);
	}
}

void findSize(int node) {
	treeSize[node] = 1;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];

		findSize(next);

		treeSize[node] += treeSize[next];
	}
}

int main() {
	FastIO;

	cin >> N >> R >> Q;

	int U, V;

	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		arr[U].push_back(V);
		arr[V].push_back(U);
	}

	int t;

	for (int i = 0; i < Q; i++) {
		cin >> t;
		q.push_back(t);
	}

	makeTree(0, R);
	findSize(R);

	for (int i = 0; i < q.size(); i++) {
		cout << treeSize[q[i]] << "\n";
	}

	return 0;
}