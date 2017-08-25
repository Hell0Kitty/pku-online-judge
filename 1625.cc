#include<iostream>

using namespace std;

struct e{

    int p[51];

    int end;

}trie[501];

int n,m,K;

int hash[600];

int state=1;

int f[501];

void build(char c[]){

    int i,j=0,k;

    for(i=1;;)

    {

        if(trie[i].p[hash[c[j]]]==0)

            trie[i].p[hash[c[j]]]=++state;

        i=trie[i].p[hash[c[j]]];

        j++;

        if(j>=strlen(c))

            break;

    }

    trie[i].end=1;

}

void ac(){

    int q[501];

    int l=0,r=0;

    int i,j,k;

    for(i=0;i<n;i++)

        if(trie[1].p[i])

        {

            q[++r]=trie[1].p[i];

            f[trie[1].p[i]]=1;

        }

        else

        {

            trie[1].p[i]=1;

        }

    while(l<r){

        i=q[++l];

        for(j=0;j<n;j++)

        {

            if(trie[i].p[j])

            {

                q[++r]=trie[i].p[j];

                k=f[i];

                while(!trie[k].p[j])

                    k=f[k];

                f[trie[i].p[j]]=trie[k].p[j];

                trie[trie[i].p[j]].end|=trie[trie[k].p[j]].end;

            }

        }

    }

}

int dp[51][501][100];

void plus(int *a,int *b){

    int i,j=0,k;

    int c[101];

    for(i=0;i<99;i++)

    {

        k=a[i]+b[i]+j;

        c[i]=k%10000;

        j=k/10000;

    }

    for(i=0;i<99;i++)

        a[i]=c[i];

}

void print(int *a){

    int i,j,k;

    j=99;

    while(j>=0&&a[j]==0)

        j--;

    if(j==-1)

    {

        cout<<0<<endl;

        return;

    }

    cout<<a[j];cout.fill('0');

    for(i=j-1;i>=0;i--)

    {

        cout.width(4);

        cout<<a[i];

    }

    cout<<endl;

}

void Pr(int *r)

{

  int i;

  for(i=99;i>0;i--)

    if (r[i]!=0)

      break;

  cout<<r[i];    

  cout.fill('0');

  for(i--;i>=0;i--)

    {

    cout.width(4);

    cout<<r[i];               

    }

  cout<<endl;  

}

void loop(){

    int i,j,k,s;

    for(i=1;i<=state;i++)

        if(trie[i].end==0)

            dp[0][i][0]=1;

    for(s=0;s<m;s++) 

    for(i=1;i<=state;i++)

        if(trie[i].end)

            continue;

        else

        {

            for(j=0;j<n;j++)

                if(trie[i].p[j])

                {

                    k=trie[i].p[j];

                    if(trie[k].end==0)

                        plus(dp[s+1][i],dp[s][k]);

                }

                else

                {

                    k=f[i];

                    while(!trie[k].p[j])

                        k=f[k];

                    if(!trie[trie[k].p[j]].end)

                    {

                        k=trie[k].p[j];

                        plus(dp[s+1][i],dp[s][k]);

                    }

                }

        }

}

void read(){

    int i,j,k;

    char c[60];

    cin>>n>>m>>K;

    cin>>c;

    for(i=0;i<strlen(c);i++)

        hash[c[i]]=i;

    for(i=1;i<=K;i++)

    {

        cin>>c;

        build(c);

    }

    ac();

    loop();

    print(dp[m][1]);

}

int main(){

    read();

    return 0;

}



