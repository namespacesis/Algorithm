#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int N;
int arr[100000];
int freq[1000];
int arr2[2000];

int main(void) {
    scanf("%d", &N);


    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
        freq[num]++;
    }

    int v2_size = 0;

    for (int i = 1; i <= 999; i++) {
        if (freq[i] == 1) {
            arr2[v2_size++] = i;
        }
        else if (freq[i] >= 2) {
            arr2[v2_size++] = i;
            arr2[v2_size++] = i;
        }
    }

    int res = 0;

    for (int i = 0; i < v2_size - 1; i++) {
        for (int j = i + 1; j < v2_size; j++) {
            int tmp = arr2[i] * arr2[j];
            int sum = 0;

            while (tmp > 0) {
                sum += tmp % 10;
                tmp /= 10;
            }

            res = max(res, sum);
        }
    }

    printf("%d\n", res);

    return 0;
}
