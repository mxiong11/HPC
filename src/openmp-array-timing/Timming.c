#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // 定义数组大小，您可以根据需要调整

// 函数原型
double time_loop_order(int order);

int main(int argc, char *argv[]) {


    if (argc < 3) {
    printf("Usage: %s <order> <M>\n", argv[0]);
    return 1;
    }

    int M = atoi(argv[2]);
    //int order = atoi(argv[1]);
    
    for (int order = 1; order <= atoi(argv[1]); order++) {
        double avg_time = 0;
        for (int i = 0; i < M; i++) {
            avg_time += time_loop_order(order);
        }
        avg_time /= M;
        printf("Average time for order %d: %f seconds\n", order, avg_time);
    }
    return 0;
}

double time_loop_order(int order) {
    double A[N][N][N];
    double B[N][N][N];
    double C[N][N][N];
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // 根据 order 的值选择不同的循环顺序
    if (order == 1) {
        // 循环顺序 i-j-k
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    } else if (order == 2) {
        // 循环顺序 i-k-j
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                for (int j = 0; j < N; j++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    } else if (order == 3) {
        // 循环顺序 j-i-k
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                for (int k = 0; k < N; k++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    } else if (order == 4) {
        // 循环顺序 j-k-i
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    } else if (order == 5) {
        // 循环顺序 k-j-i
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < N; i++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    } else if (order == 6) {
        // 循环顺序 k-i-j
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    C[i][j][k] = A[i][j][k] + B[i][j][k];
                }
            }
        }
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}
