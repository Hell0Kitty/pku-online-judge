#include "iostream"
#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "cmath"
#include "algorithm"
#include "vector"
#include "list"
#include "map"
#include "queue"
#include "set"
#include "stack"
using namespace std;

#define mset(a) memset(a,0,sizeof(a))

int n, an[35];
vector<int> re;

void mswap(int x){
    int i,j,tmp;
    for(i = 0, j = x; i < j; i++,j--){
        tmp = an[i];
        an[i] = an[j];
        an[j] = tmp;
    }
}

int mfind(int x){
    for(int i = 0; i < n; i++){
        if(an[i] == x) return i;
    }
    return 0;
}

void run(){
    for(int i = n; i > 0; i--){
        int tmp = mfind(i);
        if(tmp != i-1) {
            mswap(tmp);
            if(tmp > 0) re.push_back(tmp+1);
            mswap(i-1);
            if(i > 0) re.push_back(i);
        }
    }
}

int main()
{
    while(scanf("%d",&n), n){
        for(int i = 0; i < n; i++){
            scanf("%d",&an[i]);
        }
        re.clear();
        run();
        printf("%d",re.size());
        for(int i = 0; i < re.size(); i++) printf(" %d",re[i]);
        printf("\n");
    }
    return 0;
}



