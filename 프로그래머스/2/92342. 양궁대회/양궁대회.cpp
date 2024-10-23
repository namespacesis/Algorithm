#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
vector<int> v;
int res = 0;
vector<int> infos;
vector<int> r;

int cal(vector<int>& s) {
    int ret = 0;
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < 11; i++) {
        if (s[i] != 0 && s[i] > infos[i]) {
            res2 += (10 - i);
        }
        else if (infos[i] != 0 && infos[i] > s[i]) {
            res1 += (10 - i);
        }
    }
    ret = res2 - res1;
    return ret;
}

void dfs(vector<int> s, int cnt, int idx) {
    if (idx == 11 && cnt < N) {
        for (int i = 0; i < N - cnt; i++) {
            s[10]++;
        }
        if (cal(s) > res) {
            res = cal(s);
            r = s;
        }
        else if (cal(s) == res) {
            for (int i = 10; i >= 0; i--) {
                if (r[i] > s[i]) {
                    break;
                }
                else if (r[i] < s[i]) {
                    r = s;
                    break;
                }
            }
        }
        return;
    }
    
    if (cnt > N) return;
    
    if (cnt == N) {
        if (cal(s) > res) {
            res = cal(s);
            r = s;
        }
        else if (cal(s) == res) {
            for (int i = 10; i >= 0; i--) {
                if (r[i] > s[i]) {
                    break;
                }
                else if (r[i] < s[i]) {
                    r = s;
                    break;
                }
            }
        }
        return;
    }
    
    for (int i = idx; i < 11; i++) {
        vector<int> temp = s;
        temp[i] = v[i];
        dfs(temp, cnt + v[i], i + 1);
        dfs(s, cnt, i + 1);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    N = n;
    
    for (auto x : info) {
        v.push_back(x + 1);
    }
    
    vector<int> s;
    
    infos = info;
    
    for (int i = 0; i < 11; i++) {
        s.push_back(0);
        r.push_back(0);
    }
    
    dfs(s, 0, 0);
    
    if (res == cal(info)) {
        answer.push_back(-1);
    }
    else {
        answer = r;
    }
    
    return answer;
}