#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    const double epsilon = 1e-7;
    double omega_s = 6.0; // 초침 각속도 (deg/s)
    double omega_m = 0.1; // 분침 각속도 (deg/s)
    double omega_h = 0.5 / 60.0; // 시침 각속도 (deg/s)

    // 시작 시간부터의 총 초
    double total_time = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);

    // 각 바늘의 초기 각도 계산
    double theta_s = s1 * 6.0;
    double theta_m = m1 * 6.0 + s1 * 0.1;
    double theta_h = (h1 % 12) * 30.0 + m1 * 0.5 + s1 * (0.5 / 60.0);

    // 상대 각속도
    double omega_sm = omega_s - omega_m;
    double omega_sh = omega_s - omega_h;

    // 각도 차이
    double deltaTheta_sm = fmod((theta_m - theta_s + 360.0), 360.0);
    double deltaTheta_sh = fmod((theta_h - theta_s + 360.0), 360.0);

    // 겹치는 시간 계산
    double t0_sm = deltaTheta_sm / omega_sm;
    double t0_sh = deltaTheta_sh / omega_sh;

    // 겹침 주기
    double P_sm = 360.0 / omega_sm;
    double P_sh = 360.0 / omega_sh;

    vector<double> times;

    // 초침과 분침의 겹치는 시간 추가
    for (int n = 0;; ++n) {
        double t = t0_sm + n * P_sm;
        if (t > total_time) break;
        if (t >= 0 && t <= total_time) {
            times.push_back(t);
        }
    }

    // 초침과 시침의 겹치는 시간 추가
    for (int n = 0;; ++n) {
        double t = t0_sh + n * P_sh;
        if (t > total_time) break;
        if (t >= 0 && t <= total_time) {
            times.push_back(t);
        }
    }

    // 시간 정렬 및 중복 제거
    sort(times.begin(), times.end());

    int answer = 0;
    double prev_time = -1.0;

    for (double t : times) {
        if (prev_time < 0 || fabs(t - prev_time) > epsilon) {
            answer++;
            prev_time = t;
        }
    }

    return answer;
}
