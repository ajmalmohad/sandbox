#define NN_IMPLEMENTATION
#define NN_DEBUG
#include "nn.h"

typedef struct {
    int layers;
    Mat a0;
    Mat w1, b1, a1;
    Mat w2, b2, a2;
} Xor;

void forward_xor(Xor xor);
float cost(Xor xor, Mat tin, Mat tout);

Xor xor_alloc() {
    Xor xor;

    xor.a0 = mat_alloc(1, 2);

    xor.w1 = mat_alloc(2, 2);
    xor.b1 = mat_alloc(1, 2);
    xor.a1 = mat_alloc(1, 2);

    xor.w2 = mat_alloc(2, 1);
    xor.b2 = mat_alloc(1, 1);
    xor.a2 = mat_alloc(1, 1);

    return xor;
}

float td [] = {
    0, 0, 0,
    0, 1, 1,
    1, 0, 1,
    1, 1, 0
};

void forward_xor(Xor xor) {
    // Do iteratively after
    mat_dot(xor.a1, xor.a0, xor.w1);
    mat_sum(xor.a1, xor.b1);
    mat_sig(xor.a1);

    mat_dot(xor.a2, xor.a1, xor.w2);
    mat_sum(xor.a2, xor.b2);
    mat_sig(xor.a2);
}

float cost(Xor xor, Mat tin, Mat tout) {
    NN_ASSERT(tin.rows == tout.rows);
    NN_ASSERT(tout.cols == xor.a2.cols);
    size_t n = tin.rows;

    float cost = 0;
    for (size_t i = 0; i < n; i++) {
        Mat in = mat_row(tin, i);
        Mat out = mat_row(tout, i);

        mat_copy(xor.a0, in);
        forward_xor(xor);
        
        size_t m = tout.cols;
        for (size_t j = 0; j < m; j++) {
            float diff = MAT_AT(xor.a2, 0, j) -= MAT_AT(out, 0, j);
            cost += diff * diff;
        }
    }

    return cost / n;
}

void finite_diff(Xor m, Xor g, float eps, Mat train) {
    float saved;
    float c = cost(m, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1));
    for (size_t i = 0; i < m.w1.rows; i++) {
        for (size_t j = 0; j < m.w1.cols; j++) {
            saved = MAT_AT(m.w1, i, j);
            MAT_AT(m.w1, i, j) += eps;
            MAT_AT(g.w1, i, j) = (cost(m, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)) - c) / eps;
            MAT_AT(m.w1, i, j) = saved;
        }
    }

    for (size_t i = 0; i < m.b1.rows; i++) {
        for (size_t j = 0; j < m.b1.cols; j++) {
            saved = MAT_AT(m.b1, i, j);
            MAT_AT(m.b1, i, j) += eps;
            MAT_AT(g.b1, i, j) = (cost(m, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)) - c) / eps;
            MAT_AT(m.b1, i, j) = saved;
        }
    }

    for (size_t i = 0; i < m.w2.rows; i++) {
        for (size_t j = 0; j < m.w2.cols; j++) {
            saved = MAT_AT(m.w2, i, j);
            MAT_AT(m.w2, i, j) += eps;
            MAT_AT(g.w2, i, j) = (cost(m, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)) - c) / eps;
            MAT_AT(m.w2, i, j) = saved;
        }
    }

    for (size_t i = 0; i < m.b2.rows; i++) {
        for (size_t j = 0; j < m.b2.cols; j++) {
            saved = MAT_AT(m.b2, i, j);
            MAT_AT(m.b2, i, j) += eps;
            MAT_AT(g.b2, i, j) = (cost(m, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)) - c) / eps;
            MAT_AT(m.b2, i, j) = saved;
        }
    }
}

void xor_learn(Xor m, Xor g, float rate) {
    for (size_t i = 0; i < m.w1.rows; i++) {
        for (size_t j = 0; j < m.w1.cols; j++) {
            MAT_AT(m.w1, i, j) -= MAT_AT(g.w1, i, j) * rate;
        }
    }

    for (size_t i = 0; i < m.b1.rows; i++) {
        for (size_t j = 0; j < m.b1.cols; j++) {
            MAT_AT(m.b1, i, j) -= MAT_AT(g.b1, i, j) * rate;
        }
    }

    for (size_t i = 0; i < m.w2.rows; i++) {
        for (size_t j = 0; j < m.w2.cols; j++) {
            MAT_AT(m.w2, i, j) -= MAT_AT(g.w2, i, j) * rate;
        }
    }

    for (size_t i = 0; i < m.b2.rows; i++) {
        for (size_t j = 0; j < m.b2.cols; j++) {
            MAT_AT(m.b2, i, j) -= MAT_AT(g.b2, i, j) * rate;
        }
    }
}

int main(void) {
    Xor xor = xor_alloc();
    Xor grad = xor_alloc();

    mat_rand(xor.w1, 0, 1);
    mat_rand(xor.b1, 0, 1);
    mat_rand(xor.w2, 0, 1);
    mat_rand(xor.b2, 0, 1);

    Mat train = mat_alloc(4, 3);
    train.data = td;

    float eps = 1e-1;
    float rate = 1e-1;

    printf("cost: %f\n", cost(xor, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)));
    
    for (size_t i = 0; i < 10000; i++){
        finite_diff(xor, grad, eps, train);
        xor_learn(xor, grad, rate);
        printf("%ld: cost: %f\n", i, cost(xor, mat_submat(train, 0, 0, 4, 2), mat_submat(train, 0, 2, 4, 1)));
    }

#ifdef NN_DEBUG
    for (size_t i = 0; i < 2; i++){
        for (size_t j = 0; j < 2; j++){
            MAT_AT(xor.a0, 0, 0) = i;
            MAT_AT(xor.a0, 0, 1) = j;
            forward_xor(xor);
            float y = MAT_AT(xor.a2, 0, 0);

            printf("%zu ^ %zu = %f\n", i, j, y);
        }
    }
#endif

}