#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<stdlib.h>
#define SIZE_N 6600
#define ROW 300
#define COL 20
#define HH 65536

typedef struct{
    double x,y;
}SPoint;

const double eps = 1e-7;
const double pi = acos(-1.0);
const double max = 7.072;

int hash[HH];
int PR[SIZE_N],NR[SIZE_N];
int PC[SIZE_N],NC[SIZE_N];
int markc[SIZE_N],H[ROW];
int sum[COL];
int idx , n, m;
int dir[18]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

int cmp(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}
double Dis(SPoint a,SPoint b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

SPoint Whirl(double cosl,double sinl, SPoint a, SPoint b)
{   
    b.x-= a.x; b.y-= a.y;
    SPoint c;
    c.x= b.x* cosl- b.y* sinl+ a.x;
    c.y= b.x* sinl+ b.y* cosl+ a.y;
    return c;
}

SPoint inst(SPoint u1,SPoint u2,SPoint v1,SPoint v2)
{
    SPoint ans= u1;
    double t= ((u1.x- v1.x)*(v1.y- v2.y)- (u1.y- v1.y)*(v1.x- v2.x))/
        ((u1.x- u2.x)*(v1.y- v2.y)- (u1.y- u2.y)*(v1.x- v2.x));
    ans.x+= (u2.x- u1.x)*t;
    ans.y+= (u2.y- u1.y)*t;
    return ans;
}

SPoint fun(SPoint a,SPoint b,double r)
{
    double l=Dis(a,b);
    double ans=acos((l/2)/r);
    SPoint k1=Whirl(cos(ans),sin(ans),a,b);
    SPoint k2=Whirl(cos(ans),-sin(ans),b,a);
    SPoint cent=inst(a,k1,b,k2);
    return cent;
}

void Insert_node(int r,int c)
{
    sum[c] ++;
    PR[idx] = PR[c] , NR[idx] = c;
    NR[PR[c]] = idx , PR[c] = idx;
    if(H[r] == -1){H[r] = NC[idx] = PC[idx] = idx;}
    else {
        PC[idx] = PC[H[r]] , NC[idx] = H[r];
        NC[PC[H[r]]] = idx , PC[H[r]] = idx;
    }
    markc[idx] = c;
    idx ++;
}
void Remove(int c)
{
    int i;
    for(i = NR[c];i != c;i = NR[i]){
        PC[NC[i]] = PC[i] , NC[PC[i]] = NC[i];
    }
}
void Resume(int c)
{
    int i;
    for(i = PR[c];i != c;i = PR[i]){
        PC[NC[i]] = NC[PC[i]] = i;
    }
}
int Get_num()
{
    int i,j,k;
    int count = 0;
    int sign[COL];
    memset(sign,0,sizeof(sign));
    for(i = NC[0]; i ;i = NC[i]){
        if( !sign[i] ){
            count ++;
            for(j = NR[i];j != i;j = NR[j]){
                for(k = NC[j];k != j;k = NC[k])
                    sign[markc[k]] = 1;
            }
        }
    }
    return count;
}
int Dancing_links(int num)
{
    int tmp , i ,j ,c;
    tmp = Get_num();
    if(tmp + num > m) return 0;
    if(NC[0] == 0)return 1;
    for(i = c = NC[0]; i ;i = NC[i]){
        if(sum[i] < sum[c])
            c = i;
    }
    for(i = NR[c];i != c;i = NR[i]){
        Remove( i );
        for(j = NC[i];j != i;j = NC[j]){
            Remove(  j );
        }
        if(Dancing_links(num + 1))
            return 1;
        for(j = PC[i];j != i;j = PC[j]){
            Resume( j );
        }
        Resume( i );
    }
    return 0;
}

int main()
{
    int T;
    int nr = 0;
    int i,j,k,l,bit;
    int circle[ROW];
    double high,mid,low;
    double dis;
    SPoint pt[COL];
    SPoint crt1,crt2;

    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&m);
        for(i = 1;i <= n;i ++){
            scanf("%lf%lf",&pt[i].x,&pt[i].y);
        }

        high = max , low = 0.0;
        while(low <= high){
            nr ++;            
            mid = (low + high) / 2;
            for(i = 0;i <= n;i ++){
                PC[i+1] = i , NC[i] = i + 1;
                PR[i] = NR[i] = i;
                sum[i] = 0;
            }
            NC[n] = 0;
            idx = n + 1;
            memset(H , -1 ,sizeof(H));

            for(i = l = 1;i <= n;i ++){
                bit = dir[i];
                for(j = i + 1;j <= n;j ++){
                    if(Dis(pt[i] , pt[j]) <= mid)
                        bit |= dir[j];
                }
                if(hash[bit] != nr){hash[bit] = nr , circle[l++]  = bit;}
            }

            for(i = 1;i < n;i ++){
                for(j = i + 1;j <= n;j ++){
                    dis = Dis(pt[i] , pt[j]);
                    if(dis <= mid * 2){
                        if(dis == mid * 2){
                            crt1.x = (pt[i].x + pt[j].x) / 2;
                            crt2.y = (pt[i].y + pt[j].y) / 2;
                        }
                        else crt1 = fun(pt[i] , pt[j] , mid);
                        bit = 0;
                        for(k = 1;k <= n;k ++){
                            if(k == i || k == j){bit |= dir[k]; continue;}
                            if(Dis(pt[k] , crt1) <= mid){
                                bit |= dir[k];
                            }
                        }
                        if(hash[bit] != nr){hash[bit] = nr,circle[l++] = bit;}
                        if(dis != mid * 2){
                            crt2.x = pt[i].x + pt[j].x - crt1.x;
                            crt2.y = pt[i].y + pt[j].y - crt1.y;
                            bit = 0;
                            for(k = 1;k <= n;k ++){
                                if(k == i || k == j){bit |= dir[k];continue;}
                                if(Dis(pt[k] , crt2) <= mid){
                                    bit |= dir[k];
                                }
                            }
                            if(hash[bit] != nr){hash[bit] = nr,circle[l++] = bit;}
                        }
                    }
                }
            }//end 枚举两点在圆边上

            qsort(circle+1, l - 1,sizeof(int), cmp);
            for(i = k = 1;i < l;i ++){
                for(j = 1;j <= n;j ++){
                    hash[circle[i]^dir[j]] = 0;
                }
                if(hash[circle[i]] == nr){
                    for(j = 1;j <= n;j ++){
                        if(circle[i] & dir[j]){
                            Insert_node(k , j);
                            hash[dir[j]] = 0;
                        }
                    }
                    k ++;
                }
            }
            if(Dancing_links(0)){high = mid - eps;}
            else low = mid + eps;
        }

        printf("%.6f\n",high + eps);
    }
    return 0;
}


