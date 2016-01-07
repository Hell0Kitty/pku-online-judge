#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<functional>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#include<ctime>
#define pb push_back
#define pii pair<int,int>
#define LL long long int
using namespace std;
int mat[300][300];
int main(){
    int n;
    char p[30];
    while( scanf("%d", &n) != EOF && n){
        int a, b;
        memset(mat, 0, sizeof(mat));
        while( scanf("%d %d%*c", &a, &b), a+b ){
            scanf("%s", p);
            for(int i = 0; p[i] ; ++i) mat[a][b] |= 1 << (p[i]-'a');
        }
        for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
                mat[i][j] |= mat[i][k] & mat[k][j];
        }
        while( scanf("%d %d", &a, &b), a+b){
            if(!mat[a][b]) putchar('-');
            else {
                    for(char p = 'a'; p <= 'z' ; ++p)
                        if( mat[a][b] & (1<<(p-'a')) )
                            putchar(p);
            }
            puts("");
        }
        puts("");
    }
}


