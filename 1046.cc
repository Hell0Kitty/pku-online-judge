#include <cstdio>
using namespace std;
struct color{
    int r,g,b;
}c[16];
int main(){
    int r,g,b;
    for(int i=0;i<16;i++){
        scanf("%d%d%d",&r,&g,&b);
        c[i].r=r,c[i].g=g,c[i].b=b;
    }
    while(scanf("%d%d%d",&r,&g,&b)){
        int min=255*255*3,j=0;
        if(r==-1&&g==-1&&b==-1)break;
        for(int i=0;i<16;i++){
            int t=(c[i].r-r)*(c[i].r-r)+(c[i].g-g)*(c[i].g-g)+(c[i].b-b)*(c[i].b-b);
            if(t<min)min=t,j=i;
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,c[j].r,c[j].g,c[j].b); 
    }
}
