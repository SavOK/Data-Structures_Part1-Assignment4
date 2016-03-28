#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

long optimal_weight(int W, int *bars, size_t num_bars);

int main() {
    int W;
    int num_bar, i;
    scanf("%d %d", &W, &num_bar);
    int *bars = (int *) malloc(sizeof(int) * num_bar);
    i = 0;
    while (i < num_bar) {
        scanf("%d", bars + i);
        i++;
    }
    printf("%ld\n", optimal_weight(W, bars, num_bar));
    free(bars);
}

long optimal_weight(int W, int *bars, size_t num_bars) {
    //write your code here
    int j, i;
    long  out;
    long **value = (long **) malloc(sizeof(long *) * (num_bars + 1));
    for (i = 0; i <= num_bars; ++i) {
        value[i] = (long *) calloc(W + 1, sizeof(long));
    }

    for (i = 1; i <= num_bars; ++i) {
        for (j = 0; j <= W; ++j) {
            if (bars[i - 1] > j) {
                value[i][j] = value[i - 1][j];
            } else {
                value[i][j] = MAX(value[i - 1][j],
                                  value[i - 1][j - bars[i - 1]] + bars[i - 1]);
            }
        }
    }
    out = value[num_bars][W];
    for (i = 0; i <= num_bars; ++i) {
        free(value[i]);
        value[i] = NULL;
    }
    free(value);
    return out;

}
