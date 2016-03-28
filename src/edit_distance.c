#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int min3(int val1, int val2, int val3);

int edit_distance(const char str1[], size_t len1,
                  const char str2[], size_t len2);

int main() {
    char str1[200];
    char str2[200];
    scanf("%s %s", str1, str2);
    printf("%d\n", edit_distance(str1, strlen(str1), str2, strlen(str2)));
    return 0;
}

int min3(int val1, int val2, int val3) {
    int out = val1;
    if (out > val2) out = val2;
    if (out > val3) out = val3;
    return out;
}

int edit_distance(const char str1[], size_t len1,
                  const char str2[], size_t len2) {
    int i, j;
    int insertion, deletion, match, mismatch;
    int distance;

    int **D = (int **) malloc((len1 + 1) * sizeof(int *));
    for (i = 0; i <= len1; ++i) {
        D[i] = (int *) calloc((len2 + 1), sizeof(int));
    }
    for (i = 0; i <= len1; ++i) {
        D[i][0] = i;
    }
    for (j = 0; j <= len2; ++j) {
        D[0][j] = j;
    }
    for (i = 1; i <= len1; ++i) {
        for (j = 1; j <= len2; ++j) {
            insertion = D[i][j - 1] + 1;
            deletion = D[i - 1][j] + 1;
            match = D[i - 1][j - 1];
            mismatch = D[i - 1][j - 1] + 1;
            if (str1[i - 1] == str2[j - 1]) {
                D[i][j] = min3(insertion, deletion, match);
            } else {
                D[i][j] = min3(insertion, deletion, mismatch);
            }
        }
    }
    distance = D[len1][len2];
    for (i = 0; i <= len1; ++i) {
        free(D[i]);
        D[i] = NULL;
    }
    free(D);
    return distance;
}
