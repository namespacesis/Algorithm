#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[2500];
char word[50];

int main(void) {
    scanf("%[^\n]", str);
	getchar();
	scanf("%[^\n]", word);

    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == word[0]) {
			int j = 0;
			while (word[j] != '\0') {
				if (str[i + j] != word[j]) {
					break;
				}
				j++;
			}
			if (word[j] == '\0') {
				res++;
				i += j - 1;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}
