#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int cnt = 0;
    int idx = 0;
    int maxV = number[idx] - '0';

    while (cnt < k) {
        int e = k - cnt + idx;
        for (int i = idx + 1; i <= e; i++) {
            if ((number[i] - '0') > maxV) {
                maxV = number[i] - '0';
                cnt += i - idx;
                idx = i;
                if (cnt == k) {
                    break;
                }
            }
        }
        answer += number[idx];
        if (answer.size() == number.size() - k) break;
        maxV = number[idx + 1] - '0';
        idx++;
    }
        
    if (answer.size() < number.size() - k) {
        answer += number.substr(idx, number.size());
    }
    
    return answer;
}