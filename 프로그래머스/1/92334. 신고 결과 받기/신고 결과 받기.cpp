#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
#include <iostream>

using namespace std;

int chk[1000];
bool visited[1000][1000];
set<int> arr[1000];
unordered_map<string, int> um;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for (int i = 0; i < id_list.size(); i++) {
        um[id_list[i]] = i;
    }
    
    int t = 0;
    
    for (string str : report) {
        stringstream ss(str);
        string user1, user2;
        
        ss >> user1 >> user2;
        
        if (visited[um[user1]][um[user2]]) continue;
        
        visited[um[user1]][um[user2]] = true;
        chk[um[user2]]++;
        arr[um[user1]].insert(um[user2]);
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        int ret = 0;
        
        for (int idx : arr[i]) {
            if (chk[idx] >= k) {
                ret++;
            }
        }
        
        answer.push_back(ret);
    } 
    
    return answer;
}