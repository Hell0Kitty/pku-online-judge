#include<iostream>

using namespace std;

int n;

struct e{

    int x1,y1,x2,y2,c;

};

e a[16];

struct ee{

    int data;

    ee *next;

};

ee edge[16];

int ans;

int d[16];

int v[16];

void solve(int num,int value,int color){

    int i,j,k;

    if(value>ans) return;

    if(num==n)

    {

        ans=value;

        return;

    }

    for(i=1;i<=n;i++)

    {

        if(d[i]==0&&v[i]==0)

        {

            v[i]=1;

            ee *p=edge[i].next;

            while(p){

                d[p->data]--;

                p=p->next;

            }

            if(color!=a[i].c) solve(num+1,value+1,a[i].c);

            else solve(num+1,value,color);

            p=edge[i].next;

            while(p)

            {

                d[p->data]++;

                p=p->next;

            }

            v[i]=0;

        }

    }

}

void build(){

    int i,j,k;

    for(i=1;i<=n;i++)

    {

        edge[i].data=i;

        edge[i].next=0;

    }

    for(i=1;i<=n;i++)

        for(j=1;j<=n;j++)

        {

            if(a[j].x1==a[i].x2&&((a[i].y1>=a[j].y1&&a[i].y1<a[j].y2)||(a[j].y1>=a[i].y1&&a[j].y1<a[i].y2)))

            {

                ee *p=new ee;

                p->data=j;

                p->next=edge[i].next;

                edge[i].next=p;

                d[j]++;

            }

        }

}

void read(){

    int i,j,k;

    int cas;

    cin>>cas;

    while(cas--)

    {

        memset(d,0,sizeof(d));

        memset(v,0,sizeof(v));

        cin>>n;

        ans=n+1;

        for(i=1;i<=n;i++)

            cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].c;

        build();

        solve(0,0,0);

        cout<<ans<<endl;

    }

}

int main(){

    read();

    return 0;

}



