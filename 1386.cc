#include<iostream>

#include<fstream>

#include<vector>

using namespace std;

int in[30];

int out[30];

int n;

int v[30];

vector<int> edge[27];

void dfs(int s){

    v[s]=1;

    for(int i=0;i<edge[s].size();i++)

        if(v[edge[s][i]]==0)

            dfs(edge[s][i]);

}

int ok(int s){

    int i;

    memset(v,0,sizeof(v));

    dfs(s);

    for(i=0;i<26;i++)

        if(v[i]==0&&edge[i].size()!=0)

            return 0;

    return 1;

}

void read(){

//  ifstream cin("in.txt");

    int i,j,k;

    cin>>k;

    char c[1010];

    while(k--)

    {

        memset(in,0,sizeof(in));

        memset(out,0,sizeof(out));

        int f=0;

        cin>>n;

        for(i=0;i<26;i++)

            edge[i].clear();

        for(i=1;i<=n;i++)

        {

            cin>>c;

            out[c[0]-'a']++;

            in[c[strlen(c)-1]-'a']++;

            edge[c[0]-'a'].push_back(c[strlen(c)-1]-'a');

            edge[c[strlen(c)-1]-'a'].push_back(c[0]-'a');

        }

        if(!ok(c[0]-'a'))

        {

            cout<<"The door cannot be opened."<<endl;

            continue;

        }

        for(i=0;i<26;i++)

            if(in[i]!=out[i])

            {

                if(in[i]<out[i])

                {

                    if(f==0&&in[i]-out[i]==-1)

                    {

                        f=1;

                    }

                    else

                        break;

                }

            }

        if(i<26)

            cout<<"The door cannot be opened."<<endl;

        else

            cout<<"Ordering is possible."<<endl;

    }

}

int main(){

    read();

    return 0;

}


