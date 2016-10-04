#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
int b[35];
int A[35][35];
void elem_trans(int N){//对N*(N+1)的增广矩阵做行初等变换
    for (int r = 0, col = 0; r < N - 1 && col <= N;) {//对前n-1行
        if (A[r][col] == 0) {//可能需要做行交换
            int i;
            for (i = r + 1; i < N; i++) {//从下一行开始找
                if (A[i][col] == 1) {
                    for (int j = col; j <= N; j++) {//行交换
                        swap(A[i][j], A[r][j]);
                    }
                    break;
                }
            }
            if (i == N) {
                col++;//指针移到下一列
                continue;
            }
        }
        for (int r2 = r + 1; r2 < N; r2++) {//用第r行对下面的行消元
            if (A[r2][col] == 1) {
                for (int j = col; j <= N; j++) {
                    A[r2][j] ^= A[r][j];
                }
            }
        }
        r++, col++;
    }
}
bool is_equal(int *x, int begin, int end, int val){
    for (int i = begin; i < end; i++) {
        if (x[i] != val) {
            return false;
        }
    }
    return true;
}

int calc(int N){
    for (int i = 0; i < N; i++) {
        if (is_equal(A[i], 0, N, 0)) {
            for (int j = i; j < N; j++) {
                if (A[j][N] == 1) {
                    return -1;//impossible
                }
            }
            return 1 << (N - i);//pow(2, N - i);//有解，且有N-i个自由变量
        }
    }
    return 1;
}

int main(int argc, const char *argv[])
{
    int K, N;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        memset(b, 0, sizeof(b));
        memset(A, 0, sizeof(A));
        for (int j = 0; j < N; j++) {
            scanf("%d", &b[j]);
        }
        for (int j = 0, tmp; j < N; j++) {
            scanf("%d", &tmp);
            b[j] ^= tmp;
        }
        int s, t;
        while (scanf("%d%d", &s, &t) != EOF && s != 0) {
            A[t - 1][s - 1] = 1;
        }
        for (int j = 0; j < N; j++) {
            A[j][j] = 1;
            A[j][N] = b[j];
        }
        elem_trans(N);
        int res = calc(N);
        if (res < 0) {
            printf("Oh,it's impossible~!!\n");
        }else{
            printf("%d\n", res);
        }
    }
    return 0;
}



