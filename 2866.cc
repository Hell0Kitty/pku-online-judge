#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<memory.h>
#include<map>
#include<stdio.h>
using namespace std;
string s;
vector<int>adj[1002];
vector<pair<int,int> > c[1002];
double res[1002][52];
const double INF=400000000;
map<string,int>M;
double g(int a,int b,int c1,int d)
{
	int x1,x2,y2,y1;
	x1=c[a][b].first;
	y1=c[a][b].second;
	x2=c[c1][d].first;
	y2=c[c1][d].second;
	return sqrt(double((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
double f(int s,int ct, int p)
{
//	cout<<"f("<<s<<","<<ct<<","<<p<<endl;

	double ans=0,tmp=INF;

	if(res[s][ct]!=-1)
		return res[s][ct];

	//if(adj[s].size()==1 && s!=0)
		//return res[s][ct]=0;
	//cout<<"size "<<s<<" "<<adj[s].size()<<" "<<adj[s][0]<<" "<<adj[s][1]<<endl;

	for(int i=0; i<adj[s].size(); i++)
	{

		if(adj[s][i]!=p)
		{	
			//cout<<"size= "<<adj[s][i]<<" "<<c[adj[s][i]].size()<<endl;
			tmp=INF;
			for(int j=0; j<c[adj[s][i]].size(); j++)
			{

				//cout<<"for"<<j<<" s="<<s<<" "<<adj[s].size()<<endl;
				//cout<<"i="<<i<<" "<<adj[s][i]<<endl;
				//cout<<f(adj[s][i],j,s)<<" "<<g(s,ct,adj[s][i],j)<<endl;
				//cout<<s<<"   "<<ct<<"   "<<p<<endl;
				//cout<<"tmp1="<<tmp<<endl;
				tmp=min(tmp,f(adj[s][i],j,s)+g(s,ct,adj[s][i],j));
				//if(adj[s][i]==2 && j==0 && s==0)
					//cout<<f(adj[s][i],j,s)<<"  "<<g(s,ct,adj[s][i],j)<<" "<<tmp<<endl;

			}
		//cout<<"tmp="<<tmp<<endl;
		ans+=tmp;
		}	
	}
	//cout<<"ans="<<ans<<endl;
	return res[s][ct]=ans;
}

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		for(int i=0; i<n; i++)
		{
			adj[i].clear();
			c[i].clear();
			for(int j=0; j<50; j++)
				res[i][j]=-1;
		}
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>s>>x;
			M[s]=i;
			for(int j=0; j<x; j++)
			{
				pair<int,int>p;
				cin>>p.first>>p.second;
				c[i].push_back(p);
			}
		}
		for(int i=0; i<n-1; i++)
		{
			string x,y;
			cin>>x>>y;
			adj[M[x]].push_back(M[y]);
			adj[M[y]].push_back(M[x]);
		}
		double ans=INF;
		for(int j=0; j<c[0].size(); j++)
			ans=min(ans,f(0,j,0));
		printf("%.1lf",ans);
		cout<<endl;
		cin>>n;
	}
}



