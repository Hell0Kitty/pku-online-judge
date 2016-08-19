#include <cstdio>
#define N 300+1
#define M 200
using namespace std;
bool useful[M][N];
bool killed[M];

int test(int tester,int end){
    bool cover[N]={0};
    int other,i;

    for(other=0;other<end;other++){
        if(other==tester||killed[other]) continue;

        for(i=0;i<N;i++){
            if((useful[other][i]&&!useful[tester][i])){
                break;
            }
        }

        if(i<N) continue;
        for(i=0;i<N;i++){
            if(useful[other][i]) cover[i]=1;
        }
    }

    for(i=0;i<N;i++){
        if(useful[tester][i]&&!cover[i]) return 0;
    }

    killed[tester]=1;

    return 1;
}

void solve(int numOfDisease,int numOfMedicine){
for(int i=0;i<M;i++) for(int j=0;j<N;j++) useful[i][j]=0;
for(int i=0;i<M;i++) killed[i]=0;

    int getlevel,hit;
    for(int i=0;i<numOfMedicine;i++){
        scanf("%d",&getlevel);
        for(int j=0;j<getlevel;j++){
            scanf("%d",&hit);
            useful[i][hit]=1;
        }
    }

    int total=0;
    for(int i=0;i<numOfMedicine;i++){
        total+=test(i,numOfMedicine);
    }
    printf("%d\n",total);
}

int main()
{
    int n,m;
    for(scanf("%d%d",&n,&m);!(n==0&&m==0);scanf("%d%d",&n,&m)) solve(n,m);
    return 0;
}



