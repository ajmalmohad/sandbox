#define NN_IMPLEMENTATION
// #define NN_DEBUG
#include "nn.h"

float td [] = {
    0, 0, 0,
    0, 1, 1,
    1, 0, 1,
    1, 1, 0
};

int main(void) {
    srand(time(0));

    Mat train = mat_alloc(4, 3);
    train.data = td;

    Mat tin = mat_submat(train, 0, 0, 4, 2);
    Mat tout = mat_submat(train, 0, 2, 4, 1);

    float eps = 1e-1;
    float rate = 1e-1;

    size_t arch [] = {2, 2, 1};
    NN nn = nn_alloc(arch, ARRAY_LEN(arch));
    NN grad = nn_alloc(arch, ARRAY_LEN(arch));
    nn_rand(nn, 0, 1);

    for (size_t i = 0; i < 20*1000; i++){
        nn_finite_diff(nn, grad, eps, tin, tout);
        nn_learn(nn, grad, rate);
    }

    printf("cost: %f\n", nn_cost(nn, tin, tout));

    for (size_t i = 0; i < 2; i++){
        for (size_t j = 0; j < 2; j++){
            MAT_AT(NN_INPUT(nn), 0, 0) = i;
            MAT_AT(NN_INPUT(nn), 0, 1) = j;
            nn_forward(nn);
            printf("%zu ^ %zu = %f\n", i, j, MAT_AT(NN_OUTPUT(nn), 0, 0));
        }
    }
    

    return 0;
}