#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

long Calculator(long N, long** steps);

int main() {
    long N, num_steps;
    scanf("%ld", &N);
    long* steps = (long*) calloc(1, sizeof(long));
    num_steps = Calculator(N, &steps);
    printf("%ld\n", num_steps);
    for (long m = 0; m <= num_steps; ++m) {
        printf("%ld ", steps[m]);
    }
    printf("\n");
    free(steps);
}

long Calculator(long N, long** steps) {
    long* array = (long*) calloc((size_t) (N + 1), sizeof(long));
    array[1] = 0;
    long num_steps, curr_value;
    long A1, A2, A3;
    for (curr_value = 2; curr_value <= N; ++curr_value) {
        A1 = array[curr_value - 1] + 1;
        if (curr_value % 3 == 0) {
            A3 = array[curr_value / 3] + 1;
            array[curr_value] = MIN(A3, A1);
        } else if (curr_value % 2 == 0) {
            A2 = array[curr_value / 2] + 1;
            array[curr_value] = MIN(A2, A1);
        } else {
            array[curr_value] = A1;
        }
    }

    num_steps = array[N];

///  build steps
    long curr_step;
    curr_step = num_steps;
    curr_value = N;
    *steps = (long*) calloc((size_t) (num_steps + 1), sizeof(long));
    (*steps)[curr_step] = N;
    // Backtrack
    while (curr_value > 1 && curr_step > 0) {
        if (curr_value % 3 == 0) {
            if (array[curr_value] - array[curr_value / 3] == 1) {
                curr_value /= 3;
            }
            else if (array[curr_value] - array[curr_value - 1] == 1) {
                curr_value -= 1;
            }
        } else if (curr_value % 2 == 0) {
            if (array[curr_value] - array[curr_value / 2] == 1) {
                curr_value /= 2;
            }
            else if (array[curr_value] - array[curr_value - 1] == 1) {
                curr_value -= 1;
            }
        } else if (array[curr_value] - array[curr_value - 1] == 1) {
            curr_value -= 1;
        } else { printf("test 1\n"); }
        (*steps)[--curr_step] = curr_value;
    }
    (*steps)[0] = 1;

    free(array);
    array = NULL;
    return num_steps;
}
