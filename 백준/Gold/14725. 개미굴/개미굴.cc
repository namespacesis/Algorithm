#include <iostream>
#include <map>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct Node {
	map<string, Node*> m;
};

Node* head;

void print(Node* cur, string depth) {
	for (auto& s : cur->m) {
		cout << depth + s.first << "\n";
		print(s.second, depth + "--");
	}
}

int N;

int main() {
	FastIO;

	cin >> N;

	int K;

	string food;

	head = new Node;

	for (int i = 0; i < N; i++) {
		cin >> K;

		Node* cur = head;

		while (K--) {
			cin >> food;

			if (cur->m.find(food) == cur->m.end()) {
				cur->m[food] = new Node;
			}

			cur = cur->m[food];
		}
	}

	print(head, "");

	return 0;
}