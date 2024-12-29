#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int index;    // 행 번호
    Node* prev;   // 이전 노드
    Node* next;   // 다음 노드
};

string solution(int n, int k, vector<string> cmd) {
    // 이중 연결 리스트 생성
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
        nodes[i]->index = i;
    }
    
    for(int i = 0; i < n; i++){
        if (i > 0) nodes[i]->prev = nodes[i - 1];
        if (i < n - 1) nodes[i]->next = nodes[i + 1];
    }

    Node* cur = nodes[k];  // 현재 선택된 노드
    stack<Node*> removed;   // 삭제된 노드 기록

    for (const string& c : cmd) {
        if (c[0] == 'U') {
            int x = stoi(c.substr(2));  // 위로 이동할 칸 수
            while (x--) cur = cur->prev;
        } else if (c[0] == 'D') {
            int x = stoi(c.substr(2));  // 아래로 이동할 칸 수
            while (x--) cur = cur->next;
        } else if (c[0] == 'C') {
            removed.push(cur);  // 현재 노드를 삭제 스택에 기록
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            cur = (cur->next) ? cur->next : cur->prev;  // 아래 또는 위로 이동
        } else if (c[0] == 'Z') {
            Node* restore = removed.top();  // 복구할 노드
            removed.pop();
            if (restore->prev) restore->prev->next = restore;
            if (restore->next) restore->next->prev = restore;
        }
    }

    // 결과 문자열 생성
    string answer(n, 'O');
    while (!removed.empty()) {
        answer[removed.top()->index] = 'X';
        removed.pop();
    }

    return answer;
}
