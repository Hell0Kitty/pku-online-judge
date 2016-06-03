#include<cstdio>
#include<cstring>
#define MAXN 105
int N, arr[MAXN][MAXN];
int x_used[MAXN][11], y_used[MAXN][11], n_used[MAXN][11];

int main() {
    while(scanf("%d", &N) != EOF) {
        memset(x_used, 0, sizeof(x_used));
        memset(y_used, 0, sizeof(y_used));
        memset(n_used, 0, sizeof(n_used));
        bool flag = true;
        for(int i = 0; i < N * N; ++ i) {
            for(int j = 0; j < N * N; ++ j) {
                scanf("%d", &arr[i][j]);
                if(arr[i][j] > 0 && flag) {
                    if(x_used[i][arr[i][j]] == 1) {
                        flag = false;
                    } else {
                        x_used[i][arr[i][j]] = 1;
                    }
                    if(y_used[j][arr[i][j]] == 1) {
                        flag = false;
                    } else {
                        y_used[j][arr[i][j]] = 1;
                    }
                    if(n_used[i / N * N + j / N + 1][arr[i][j]] == 1) {
                        flag = false;
                    } else {
                        n_used[i / N * N + j / N + 1][arr[i][j]] = 1;
                    }
                }
            }
        }
        if(flag) {
            printf("CORRECT\n");
        } else {
            printf("INCORRECT\n");
        }
    }
    return 0;
}



