#define NN_IMPLEMENTATION
#include "nn.h"

typedef struct {
    int layers;
    Mat a0;
    Mat w1, b1, a1;
    Mat w2, b2, a2;
} Xor;

float forward_xor(Xor xor, float x1, float x2) {
    MAT_AT(xor.a0, 0, 0) = x1;
    MAT_AT(xor.a0, 0, 1) = x2;

    // Do iteratively after
    mat_dot(xor.a1, xor.a0, xor.w1);
    mat_sum(xor.a1, xor.b1);
    mat_sig(xor.a1);

    mat_dot(xor.a2, xor.a1, xor.w2);
    mat_sum(xor.a2, xor.b2);
    mat_sig(xor.a2);

    return MAT_AT(xor.a2, 0, 0);
}

int main(void) {
    Xor xor;

    xor.a0 = mat_alloc(1, 2);

    xor.w1 = mat_alloc(2, 2);
    xor.b1 = mat_alloc(1, 2);
    xor.a1 = mat_alloc(1, 2);

    xor.w2 = mat_alloc(2, 1);
    xor.b2 = mat_alloc(1, 1);
    xor.a2 = mat_alloc(1, 1);

    mat_rand(xor.w1, 0, 1);
    mat_rand(xor.b1, 0, 1);
    mat_rand(xor.w2, 0, 1);
    mat_rand(xor.b2, 0, 1);

    for (size_t i = 0; i < 2; i++){
        for (size_t j = 0; j < 2; j++){
            printf("%zu ^ %zu = %f\n", i, j, forward_xor(xor, i, j));
        }
    }

    return 0;
}