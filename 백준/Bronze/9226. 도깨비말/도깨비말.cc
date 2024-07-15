#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
    char word[20];

    while (1) {
        scanf("%s", word);
        if (strcmp(word, "#") == 0) {
            break;
        }

        int len = strlen(word);
        int firstVowelIndex = -1;

        for (int i = 0; i < len; i++) {
            if (isVowel(word[i])) {
                firstVowelIndex = i;
                break;
            }
        }

        if (firstVowelIndex == -1) {
            printf("%say\n", word);
        }
        else if (firstVowelIndex == 0) {
            printf("%say\n", word);
        }
        else {
            for (int i = firstVowelIndex; i < len; i++) {
                printf("%c", word[i]);
            }
            for (int i = 0; i < firstVowelIndex; i++) {
                printf("%c", word[i]);
            }
            printf("ay\n");
        }
    }

    return 0;
}