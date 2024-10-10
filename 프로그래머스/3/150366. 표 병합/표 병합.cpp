#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

string arr[51][51];
pair<int, int> parent[51][51];
unordered_map<string, set<pair<int, int>>> um;
unordered_map<int, vector<pair<int, int>>> um2;

pair<int, int> getParent(int x, int y) {
    if (parent[x][y].first == x && parent[x][y].second == y) return {x, y};
    return parent[x][y] = getParent(parent[x][y].first, parent[x][y].second);
}

void unionParent(pair<int, int> a, pair<int, int> b) {
    a = getParent(a.first, a.second);
    b = getParent(b.first, b.second);
    
    if (a == b) return;
    
    string value = arr[a.first][a.second] != "" ? arr[a.first][a.second] : arr[b.first][b.second];
    
    int hashCodeA = a.first * 100 + a.second;
    int hashCodeB = b.first * 100 + b.second;
    if (arr[a.first][a.second] != "") {
        parent[b.first][b.second] = a;
        um[arr[b.first][b.second]].erase({b.first, b.second});
        um[value].insert({b.first, b.second});
        arr[b.first][b.second] = value;
        
        for (pair<int, int> u : um2[hashCodeB]) {
            string temp = arr[u.first][u.second];
            um2[hashCodeA].push_back(u);
            um[temp].erase({u.first, u.second});
            um[value].insert({u.first, u.second});
            arr[u.first][u.second] = value;
            parent[u.first][u.second] = a;
        }
        um2[hashCodeB].clear();
        um2[hashCodeA].push_back({b.first, b.second});
    }
    else {
        parent[a.first][a.second] = b;
        um[arr[a.first][a.second]].erase({a.first, a.second});
        um[value].insert({a.first, a.second});
        arr[a.first][a.second] = value;
        
        for (pair<int, int> u : um2[hashCodeA]) {
            string temp = arr[u.first][u.second];
            um2[hashCodeB].push_back(u);
            um[temp].erase({u.first, u.second});
            um[value].insert({u.first, u.second});
            arr[u.first][u.second] = value;
            parent[u.first][u.second] = b;
        }
        um2[hashCodeA].clear();
        um2[hashCodeB].push_back({a.first, a.second});
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parent[i][j] = {i, j};
        }
    }
    
    for (int i = 0; i < commands.size(); i++) {
        stringstream ss(commands[i]);
        string c;
        vector<string> cv;
        
        while (getline(ss, c, ' ')) {
            cv.push_back(c);
        }
        
        if (cv[0] == "UPDATE") {
            if (cv.size() == 4) {
                pair<int, int> idx = getParent(stoi(cv[1]), stoi(cv[2]));
                string temp = arr[idx.first][idx.second];
                arr[idx.first][idx.second] = cv[3];
                int hashCode = idx.first * 100 + idx.second;
                for (pair<int, int> u : um2[hashCode]) {
                    arr[u.first][u.second] = cv[3];
                    um[temp].erase({u.first, u.second});
                    um[cv[3]].insert({u.first, u.second});
                }
                um[temp].erase({idx.first, idx.second});
                um[cv[3]].insert({idx.first, idx.second});
            }
            else if (cv.size() == 3) {
                vector<pair<int, int>> toErase;  // 삭제할 요소를 임시로 저장
                vector<pair<int, int>> toInsert;  // 추가할 요소를 임시로 저장

                for (pair<int, int> v : um[cv[1]]) {
                    arr[v.first][v.second] = cv[2];
                    toErase.push_back(v);  // 삭제할 목록에 추가
                    toInsert.push_back(v);  // 추가할 목록에 추가
                }

                // 반복문이 끝난 후 삭제 및 삽입을 처리
                for (auto v : toErase) {
                    um[cv[1]].erase(v);  // 안전하게 삭제
                }
                for (auto v : toInsert) {
                    um[cv[2]].insert(v);  // 안전하게 추가
                }
            }
        }
        else if (cv[0] == "MERGE") {
            unionParent({stoi(cv[1]), stoi(cv[2])}, {stoi(cv[3]), stoi(cv[4])});
        }
        else if (cv[0] == "UNMERGE") {
            pair<int, int> idx = getParent(stoi(cv[1]), stoi(cv[2]));
            string temp = arr[idx.first][idx.second];
            
            int hashCode = idx.first * 100 + idx.second;
            for (pair<int, int> u : um2[hashCode]) {
                parent[u.first][u.second] = {u.first, u.second};
                arr[u.first][u.second] = "";
                um[temp].erase({u.first, u.second});
            }
            um2[hashCode].clear();
            arr[idx.first][idx.second] = "";
            um[temp].erase({idx.first, idx.second});
            arr[stoi(cv[1])][stoi(cv[2])] = temp;
            um[temp].insert({stoi(cv[1]), stoi(cv[2])});
        }
        else {
            string temp = arr[stoi(cv[1])][stoi(cv[2])];
            if (temp != "") {
                answer.push_back(temp);
            }
            else {
                answer.push_back("EMPTY");
            }
        }
    }
        
    return answer;
}