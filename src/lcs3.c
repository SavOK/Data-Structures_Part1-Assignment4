#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SIZE_L sizeof(long)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


long max3(long val1, long val2, long val3);


long lcs3(const long* strA, size_t size_a,
          const long* strB, size_t size_b,
          const long* strC, size_t size_c);

long lcs2(const long* strA, size_t size_a, 
        const long* strB, size_t size_b);


int main() {
    size_t size_a, size_b, size_c;
    long i;
    long* strA, * strB, * strC;
    scanf("%ld", &size_a);
    strA = (long*) calloc(size_a, SIZE_L);
    i = 0;
    while (i < size_a) {
        scanf("%ld", &strA[i++]);
    }
    scanf("%ld", &size_b);
    strB = (long*) calloc(size_b, SIZE_L);
    i = 0;
    while (i < size_b) {
        scanf("%ld", &strB[i++]);
    }
    scanf("%ld", &size_c);
    strC = (long*) calloc(size_c, SIZE_L);
    i = 0;
    while (i < size_c) {
        scanf("%ld", &strC[i++]);
    }

//    printf("Test:\n");
//    for (i = 0; i < size_a; ++i) {
//        printf("%ld ", strA[i]);
//    }
//    printf("\n");
//    for (i = 0; i < size_b; ++i) {
//        printf("%ld ", strB[i]);
//    }
//    printf("\n");
//    for (i = 0; i < size_c; ++i) {
//        printf("%ld ", strC[i]);
//    }
//    printf("\nEND TEST\n");

    long LCS3 = lcs3(strA, size_a, strB, size_b, strC, size_c);
    printf("%ld\n", LCS3);
}

long max3(long val1, long val2, long val3) {
    long out = val1;
    if (out < val2) out = val2;
    if (out < val3) out = val3;
    return out;
}

long lcs2(const long* strA, size_t size_a, const long* strB, size_t size_b) {
    long i, j, out;
    long** C;
    C = (long**) malloc((size_a + 1) * sizeof(long*));
    for (i = 0; i <= size_a; ++i) {
        C[i] = (long*) calloc(size_b + 1, SIZE_L);
    }
    for (i = 1; i <= size_a; ++i) {
        for (j = 1; j <= size_b; ++j) {
            if (strA[i] == strB[j]) {
                C[i][j] = C[i - 1][j - 1] + 1;
            }
            else {
                C[i][j] = MAX(C[i][j - 1], C[i - 1][j]);
            }
        }
    }
    out = C[size_a][size_b];
    for (i = 0; i <= size_a; ++i) {
        free(C[i]);
        C[i] = NULL;
    }
    free(C);
    C = NULL;
    return out;
}


long lcs3(const long* strA, size_t size_a,
          const long* strB, size_t size_b,
          const long* strC, size_t size_c) {
    long i, j, k, out;
    long*** C;
    C = (long***) malloc((size_a + 1) * sizeof(long**));
    for (i = 0; i <= size_a; ++i) {
        C[i] = (long**) malloc((size_b + 1) * sizeof(long*));
        for (j = 0; j <= size_b; ++j) {
            C[i][j] = (long*) calloc(size_c + 1 , SIZE_L);
        }
    }

    for (i = 1; i <= size_a; ++i) {
        for (j = 1; j <= size_b; ++j) {
            for (k = 1; k <= size_c; ++k) {
                if ((strA[i - 1] == strB[j - 1]) &&
                    (strB[j - 1] == strC[k - 1])) {
                    C[i][j][k] = C[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    C[i][j][k] = max3(C[i - 1][j][k],
                                      C[i][j - 1][k],
                                      C[i][j][k - 1]);
                }
            }
        }
    }
    out = C[size_a][size_b][size_c];
    for (i = size_a; i >= 0; --i) {
        for (j = size_b; j >= 0; --j) {
            free(C[i][j]);
            C[i][j] = NULL;
        }
        free(C[i]);
        C[i] = NULL;
    }
    free(C);
    C = NULL;
    return out;

}
