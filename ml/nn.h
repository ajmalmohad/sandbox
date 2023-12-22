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

typedef struct {
    size_t rows;
    size_t cols;
    float *data;
} Mat;

#define MAT_AT(m, i, j) ((m).data[(i) * (m).cols + (j)])
#define MAT_PRINT(m) (mat_print(m, #m))

float rand_float(void);
float sigmoidf(float x);

Mat mat_alloc(size_t rows, size_t cols);

// Matrix only contain 3 64 bit size_tegers, so no need to pass by reference
// Matrix structure is very light weight, so we pass by value in these functions
void mat_dot(Mat dst, Mat a, Mat b);
void mat_sum(Mat dst, Mat a);
void mat_print(Mat a, const char* name);
void mat_rand(Mat a, float low, float high);
void mat_fill(Mat a, float val);
void mat_sig(Mat a);

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
    m.data = NN_MALLOC(rows * cols * sizeof(*m.data));
    
    NN_ASSERT(m.data != NULL);
    
    return m;
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

void mat_print(Mat m, const char* name){
    printf("| %s \n", name);

    for (size_t i = 0; i < m.rows; i++){
        printf("|");
        for (size_t j = 0; j < m.cols; j++){
            printf(" %f |", MAT_AT(m, i, j));
        }
        printf("\n");
    }
    
    printf("\n");
}

void mat_rand(Mat m, float low, float high){
    NN_ASSERT(low <= high);

    srand(time(0));
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

#endif // NN_IMPLEMENTATION
