#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> arr[1001];
int indegree[1001] = { 0 };
queue<int> q;
vector<int> res[1];

void topologicalSort() {
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        res[0].push_back(current);
        //cout << current << "\n";

        for (int i = 0; i < arr[current].size(); i++) {
            int next = arr[current][i];
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++) {
            cin >> temp[j];
        }
        for (int j = 1; j < k; j++) {
            arr[temp[j - 1]].push_back(temp[j]);
            indegree[temp[j]]++;
        }
    }

    topologicalSort();

    for (int i = 1; i <= N; i++) {
        if (indegree[i] > 0) {
            cout << "0";
            return 0;
        }
    }

    for (int i = 0; i < res[0].size(); i++) {
        cout << res[0][i] << "\n";
    }
    return 0;
}
