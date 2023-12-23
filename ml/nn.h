#ifndef NN_H_
#define NN_H_

#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif // NN_MALLOC

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif // NN_ASSERT

float rand_float(void);
float sigmoidf(float x);

typedef struct {
    size_t rows;
    size_t cols;
    size_t stride;
    float *data;
} Mat;

typedef struct {
    size_t count;
    Mat *weights;
    Mat *biases;
    Mat *activations; // Activations are layers + 1
} NN;

#define ARRAY_LEN(s) (sizeof((s)) / sizeof((s)[0]))
#define MAT_AT(m, i, j) ((m).data[(i) * (m).stride + (j)])
#define MAT_PRINT(m) (mat_print(m, #m, 0))
#define NN_PRINT(nn) (nn_print(nn, #nn))
#define NN_INPUT(nn) ((nn).activations[0])
#define NN_OUTPUT(nn) ((nn).activations[(nn).count])

Mat mat_alloc(size_t rows, size_t cols);
Mat mat_row(Mat m, size_t i);
Mat mat_col(Mat m, size_t j);
Mat mat_submat(Mat m, size_t i, size_t j, size_t rows, size_t cols);
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_sub_coeff(Mat dst, Mat a, float rate);
void mat_print(Mat a, const char* name, size_t padding);
void mat_rand(Mat a, float low, float high);
void mat_fill(Mat a, float val);
void mat_sig(Mat a);
void mat_copy(Mat dst, Mat a);

NN nn_alloc(size_t *arch, size_t arch_count);
void nn_print(NN nn, char* name);
void nn_rand(NN nn, float low, float high);
void nn_forward(NN nn);
float nn_cost(NN nn, Mat tin, Mat tout);
void nn_finite_diff(NN nn, NN grad, float eps, Mat tin, Mat tout);
void nn_learn(NN nn, NN grad, float rate);

#endif // NN_H_

#ifdef NN_IMPLEMENTATION

float rand_float(void) {
    return (float) rand() / (float) RAND_MAX;
}

float sigmoidf(float x) {
    return 1.0f / (1.0f + expf(-x));
}

Mat mat_alloc(size_t rows, size_t cols){
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.stride = cols;
    m.data = NN_MALLOC(rows * cols * sizeof(*m.data));
    
    NN_ASSERT(m.data != NULL);
    
    return m;
}

Mat mat_row(Mat m, size_t i){
    NN_ASSERT(i < m.rows);

    return (Mat) {
        .rows = 1,
        .cols = m.cols,
        .stride = m.stride,
        .data = &MAT_AT(m, i, 0)
    };
}

Mat mat_col(Mat m, size_t j){
    NN_ASSERT(j < m.cols);

    Mat col = mat_alloc(m.rows, 1);
    for (size_t i = 0; i < m.rows; i++){
        MAT_AT(col, i, 0) = MAT_AT(m, i, j);
    }

    return col;
}

Mat mat_submat(Mat m, size_t i, size_t j, size_t rows, size_t cols){
    NN_ASSERT(i + rows <= m.rows);
    NN_ASSERT(j + cols <= m.cols);

    Mat sub = mat_alloc(rows, cols);
    for (size_t k = 0; k < rows; k++){
        for (size_t l = 0; l < cols; l++){
            MAT_AT(sub, k, l) = MAT_AT(m, i + k, j + l);
        }
    }

    return sub;
}

void mat_dot(Mat dst, Mat a, Mat b){
    NN_ASSERT(a.cols == b.rows);
    NN_ASSERT(dst.rows == a.rows);
    NN_ASSERT(dst.cols == b.cols);

    for (size_t i = 0; i < a.rows; i++){
        for (size_t j = 0; j < b.cols; j++){
            MAT_AT(dst, i, j) = 0;
            for (size_t k = 0; k < b.rows; k++){
                MAT_AT(dst, i, j) += MAT_AT(a, i, k) * MAT_AT(b, k, j);
            }
        }
    }
}

void mat_sum(Mat dst, Mat a){
    NN_ASSERT(dst.rows == a.rows);
    NN_ASSERT(dst.cols == a.cols);

    for (size_t i = 0; i < dst.rows; i++){
        for (size_t j = 0; j < dst.cols; j++){
            MAT_AT(dst, i, j) += MAT_AT(a, i, j);
        }
    }
}

void mat_sub_coeff(Mat dst, Mat a, float rate){
    NN_ASSERT(dst.rows == a.rows);
    NN_ASSERT(dst.cols == a.cols);

    for (size_t i = 0; i < dst.rows; i++){
        for (size_t j = 0; j < dst.cols; j++){
            MAT_AT(dst, i, j) -= MAT_AT(a, i, j) * rate;
        }
    }
}

void mat_copy(Mat dst, Mat a){
    NN_ASSERT(dst.rows == a.rows);
    NN_ASSERT(dst.cols == a.cols);

    for (size_t i = 0; i < dst.rows; i++){
        for (size_t j = 0; j < dst.cols; j++){
            MAT_AT(dst, i, j) = MAT_AT(a, i, j);
        }
    }
}

void mat_print(Mat m, const char* name, size_t padding){
    printf("%*s| %s\n", (int)padding, "", name);

    for (size_t i = 0; i < m.rows; i++){
        printf("    %*s|", (int)padding, "");
        for (size_t j = 0; j < m.cols; j++){
            printf(" %f |", MAT_AT(m, i, j));
        }
        printf("\n");
    }
    
    printf("\n");
}

void mat_rand(Mat m, float low, float high){
    NN_ASSERT(low <= high);

    for (size_t i = 0; i < m.rows; i++){
        for (size_t j = 0; j < m.cols; j++){
            MAT_AT(m, i, j) = rand_float()* (high - low) + low;
        }
    }
}

void mat_fill(Mat a, float val) {
    for (size_t i = 0; i < a.rows; i++){
        for (size_t j = 0; j < a.cols; j++){
            MAT_AT(a, i, j) = val;
        }
    }
}

void mat_sig(Mat a) {
    for (size_t i = 0; i < a.rows; i++){
        for (size_t j = 0; j < a.cols; j++){
            MAT_AT(a, i, j) = sigmoidf(MAT_AT(a, i, j));
        }
    }
}

NN nn_alloc(size_t *arch, size_t arch_count) {
    NN_ASSERT(arch_count > 0);

    NN nn;
    nn.count = arch_count - 1;

    nn.weights = NN_MALLOC(nn.count * sizeof(*nn.weights));
    NN_ASSERT(nn.weights != NULL);
    nn.biases = NN_MALLOC(nn.count * sizeof(*nn.biases));
    NN_ASSERT(nn.biases != NULL);
    nn.activations = NN_MALLOC((nn.count + 1) * sizeof(*nn.activations)); 
    NN_ASSERT(nn.activations != NULL);

    nn.activations[0] = mat_alloc(1, arch[0]);
    for (size_t i = 1; i < arch_count; i++) {
        nn.weights[i - 1] = mat_alloc(arch[i - 1], arch[i]);
        nn.biases[i - 1] = mat_alloc(1, arch[i]);
        nn.activations[i] = mat_alloc(1, arch[i]);
    }

    return nn;
}

void nn_print(NN nn, char* name) {
    char buf[256];
    printf("| %s \n", name);
    for (size_t i = 0; i < nn.count; i++) {
        printf("| Layer %zu\n", i);
        snprintf(buf, sizeof(buf), "weights[%zu]", i);
        mat_print(nn.weights[i], buf, 4);
        snprintf(buf, sizeof(buf), "biases[%zu]", i);
        mat_print(nn.biases[i], buf, 4);
    }
}

void nn_rand(NN nn, float low, float high) {
    for (size_t i = 0; i < nn.count; i++) {
        mat_rand(nn.weights[i], low, high);
        mat_rand(nn.biases[i], low, high);
    }
}

void nn_forward(NN nn) {
    for (size_t i = 0; i < nn.count; i++) {
        mat_dot(nn.activations[i + 1], nn.activations[i], nn.weights[i]);
        mat_sum(nn.activations[i + 1], nn.biases[i]);
        mat_sig(nn.activations[i + 1]);
    }
}

float nn_cost(NN nn, Mat tin, Mat tout) {
    NN_ASSERT(tin.rows == tout.rows);
    NN_ASSERT(tout.cols == NN_OUTPUT(nn).cols);
    size_t n = tin.rows;

    float cost = 0;
    for (size_t i = 0; i < n; i++) {
        Mat in = mat_row(tin, i);
        Mat out = mat_row(tout, i);

        mat_copy(NN_INPUT(nn), in);
        nn_forward(nn);
        
        size_t m = tout.cols;
        for (size_t j = 0; j < m; j++) {
            float diff = MAT_AT(NN_OUTPUT(nn), 0, j) - MAT_AT(out, 0, j);
            cost += diff * diff;
        }
    }

    return cost / n;
}

void nn_finite_diff(NN nn, NN grad, float eps, Mat tin, Mat tout) {
    float saved;
    float cost = nn_cost(nn, tin, tout);

    for (size_t i = 0; i < nn.count; i++) {
        for (size_t j = 0; j < nn.weights[i].rows; j++) {
            for (size_t k = 0; k < nn.weights[i].cols; k++) {
                saved = MAT_AT(nn.weights[i], j, k);
                MAT_AT(nn.weights[i], j, k) += eps;
                MAT_AT(grad.weights[i], j, k) = (nn_cost(nn, tin, tout) - cost) / eps;
                MAT_AT(nn.weights[i], j, k) = saved;
            }
        }

        for (size_t j = 0; j < nn.biases[i].rows; j++) {
            for (size_t k = 0; k < nn.biases[i].cols; k++) {
                saved = MAT_AT(nn.biases[i], j, k);
                MAT_AT(nn.biases[i], j, k) += eps;
                MAT_AT(grad.biases[i], j, k) = (nn_cost(nn, tin, tout) - cost) / eps;
                MAT_AT(nn.biases[i], j, k) = saved;
            }
        }
    }
}

void nn_learn(NN nn, NN grad, float rate) {
    for (size_t i = 0; i < nn.count; i++) {
        mat_sub_coeff(nn.weights[i], grad.weights[i], rate);
        mat_sub_coeff(nn.biases[i], grad.biases[i], rate);
    }
}

#endif // NN_IMPLEMENTATION
