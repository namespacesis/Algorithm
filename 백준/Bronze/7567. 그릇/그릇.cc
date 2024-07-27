#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[51];
int ans = 10;

int main(void){
	scanf("%s", &a);

	for (int i = 1; i <= 50; i++) {
		if (a[i] != '(' && a[i] != ')') break;
		if (a[i - 1] == a[i]) ans += 5;
		else ans += 10;
	}

	printf("%d\n", ans);

	return 0;
}