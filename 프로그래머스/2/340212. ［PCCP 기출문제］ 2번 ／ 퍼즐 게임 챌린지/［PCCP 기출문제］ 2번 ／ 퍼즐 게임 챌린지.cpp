#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int start = 1;
    int end = 1;
    
    for (int i = 0; i < diffs.size(); i++) {
        end = max(end, diffs[i]);
    }
    
    int middle;
    
    while (start <= end) {
        middle = (start + end) / 2;
        
        bool flag = false;
        
        long long cnt = times[0];
        int time_prev = times[0];
        
        for (int i = 1; i < diffs.size(); i++) {
            if (diffs[i] <= middle) {
                cnt += times[i];
            }
            else {
                cnt += ((times[i] + time_prev) * (diffs[i] - middle)) + times[i];
            }
            
            time_prev = times[i];
            
            if (cnt > limit) {
                flag = true;
                break;
            }
        }
        
        if (flag) start = middle + 1;
        else {
            answer = middle;
            end = middle - 1;
        }
    }
        
    return answer;
}