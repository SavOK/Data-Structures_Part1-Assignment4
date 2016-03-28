#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


long MinAndMax(const char operands[],
               int i, int j, long **M, long **m);

long max5(long a, long b, long c, long d, long e);

long min5(long a, long b, long c, long d, long e);

long Parentheses(const int digits[], const char operands[], int N);

long eval(long a, long b, char op) {
    if (op == '*') { return a * b; }
    else if (op == '+') { return a + b; }
    else if (op == '-') { return a - b; }
    else { assert(0); }
}

int main() {
    char str1[200];
    scanf("%s", str1);
    int N = 0;
    int *digits = (int *) malloc(strlen(str1) * sizeof(int));
    char *operands = (char *) malloc(strlen(str1) * sizeof(char));

    // split operands and digits in different arrays
    for (int i = 0; i < strlen(str1); ++i) {
        if (i % 2 == 0) {
            digits[N] = atoi(&str1[i]);
        }
        else {
            operands[N] = str1[i];
            N++;
        }
    }
    N++; // add extra space
    printf("%ld\n", Parentheses(digits, operands, N));
    free(digits);
    free(operands);
    digits = NULL;
    operands = NULL;
    return 0 ;
}

long max5(long a, long b, long c, long d, long e) {
    long out = a;
    if (b > out) { out = b; }
    if (c > out) { out = c; }
    if (d > out) { out = d; }
    if (e > out) { out = e; }
    return out;
}

long min5(long a, long b, long c, long d, long e) {
    long out = a;
    if (b < out) { out = b; }
    if (c < out) { out = c; }
    if (d < out) { out = d; }
    if (e < out) { out = e; }
    return out;
}

long MinAndMax(const char operands[],
               int i, int j, long **M, long **m) {
    long MIN = LONG_MAX - 1;
    long MAX = LONG_MIN + 1;
    int k;
    long A, B, C, D;
    for (k = i; k <= j - 1; ++k) {

        A = eval(M[i][k], M[k + 1][j], operands[k - 1]);
        B = eval(M[i][k], m[k + 1][j], operands[k - 1]);
        C = eval(m[i][k], M[k + 1][j], operands[k - 1]);
        D = eval(m[i][k], m[k + 1][j], operands[k - 1]);

        MIN = min5(MIN, A, B, C, D);
        MAX = max5(MAX, A, B, C, D);
    }
    M[i][j] = MAX;
    m[i][j] = MIN;
    return 0;
}

// DARK MAGIC FROM LECTURES 
long Parentheses(const int digits[], const char operands[], int N) {
    int i, j, s;
    long out;
    //MAX MIN matrix to keep solutions
    long **M = (long **) malloc((N + 1) * sizeof(long *));
    long **m = (long **) malloc((N + 1) * sizeof(long *));
    for (i = 0; i <= N; ++i) {
        M[i] = (long *) calloc((N + 1), sizeof(long));
        m[i] = (long *) calloc((N + 1), sizeof(long));
    }
    for (i = 1; i <= N; ++i) {
        m[i][i] = (long) digits[i - 1];
        M[i][i] = (long) digits[i - 1];
    }

    for (s = 1; s <= N - 1; ++s) {
        for (i = 1; i <= N - s; ++i) {
            j = i + s;
            MinAndMax(operands, i, j, M, m);
        }
    }

    out = M[1][N];
    for (i = 0; i < N; ++i) {
        free(M[i]);
        free(m[i]);
        M[i] = NULL;
        m[i] = NULL;
    }
    free(m);
    free(M);
    m = NULL;
    M = NULL;
    return out;
}

