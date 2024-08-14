#include <string>
#include <vector>
#include <queue>

using namespace std;

int inedge[1000001];
int outedge[1000001];
vector<int> graph[1000001];
int res1 = 0, res2 = 0, res3 = 0;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bool visited = false;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == start && visited) {
            res1++;
            return;
        }
        
        if (graph[cur].size() >= 2) {
            res3++;
            return;
        }
        
        for (int i = 0; i < graph[cur].size(); i++) {
            q.push(graph[cur][i]);
        }
        
        visited = true;
    }
    res2++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for (int i = 0; i < edges.size(); i++) {
        inedge[edges[i][1]]++;
        outedge[edges[i][0]]++;
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    for (int i = 1; i < 1000001; i++) {
        if (inedge[i] == 0 && outedge[i] >= 2) {
            answer.push_back(i);
        }
    }
    
    vector<int> rootNode = graph[answer[0]];
    
    for (int i = 0; i < rootNode.size(); i++) {
        bfs(rootNode[i]);
    }
    
    answer.push_back(res1);
    answer.push_back(res2);
    answer.push_back(res3);

    return answer;
}