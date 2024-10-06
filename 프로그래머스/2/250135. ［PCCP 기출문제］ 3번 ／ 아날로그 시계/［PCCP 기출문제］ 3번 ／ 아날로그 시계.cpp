#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    // 시작과 끝 시간을 초 단위로 변환
    int start = h1 * 3600 + m1 * 60 + s1;
    int end = h2 * 3600 + m2 * 60 + s2;

    // 총 시간 계산
    int totalTime = end - start;

    // 초기 각도 계산 (초침, 분침, 시침)
    int tempH = (h1 % 12) * (720 * 5) + (m1 * 60 + s1) * 1;
    int tempM = (m1 * 60 + s1) * 12;
    int tempS = s1 * 720;
    int prevS, prevM, prevH;

    // 초기 시점에서 초침, 분침, 시침이 겹치는지 확인
    if (tempS == tempM || tempS == tempH)
        ++answer;

    // 시간이 지날 때마다 확인
    while (totalTime--) {
        prevS = tempS;
        prevM = tempM;
        prevH = tempH;

        // 각도를 1초에 맞게 증가
        tempH += 1;
        tempM += 12;
        tempS += 720;

        // 초침이 분침과 겹치는지 확인
        if (tempS == tempM)
            ++answer;
        else if ((prevS < prevM) != (tempS < tempM)) // 중간에서 겹칠 때
            ++answer;

        // 초침이 시침과 겹치는지 확인
        if (tempS == tempH)
            ++answer;
        else if ((prevS < prevH) != (tempS < tempH)) // 중간에서 겹칠 때
            ++answer;

        // 43200(한 바퀴) 도달 시 각도를 0으로 리셋
        if (tempS == 43200)
            tempS = 0;
        if (tempM == 43200)
            tempM = 0;
        if (tempH == 43200)
            tempH = 0;
    }

    // 12시를 넘길 때 1회 알람 감소
    if (h1 < 12 && h2 >= 12)
        --answer;

    return answer;
}