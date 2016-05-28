#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int n,x,y,a[100005];
int h,H;
priority_queue<int> q;
int main(){
    int temp,temp1,temp2;
    while(~scanf("%d%d%d%d%d",&n,&x,&y,&h,&H)){
       while(!q.empty()) q.pop();
       int mx=-1;
        temp1=h;
        temp2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int i=1;
        int flag=0;
        int flag2=0;
        while(i!=n+1){
            temp2+=x;
            mx=max(mx,min(H,temp2));
            if(temp2>=H){
                flag2=1;break;
            }
            h-=a[i];
            q.push(max(a[i],y));
            if(h<=0){
                while(h<=0&&!q.empty())
                {
                    h+=q.top();
                    q.pop();
                }
                temp2-=x;
            }
            if(h<=0){
                flag=1;
                break;
            }
            i++;
        }
        if(flag==1){
            printf("Lose\n");
            printf("%d\n",mx);
        }
        else if(i==n+1){
            printf("Lose\n");
            printf("%d\n",mx);
        }
        else if(flag2==1){
            printf("Win\n");
            printf("%d\n",i);
        }
    }
return 0;
}



