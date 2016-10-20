#include<iostream>
#include<cstring>
#include<string>
#define M 10000005
using namespace std;
string s,tmp;
int casen,ans,rad[M];
int main()
{
	while(cin>>tmp){
		if("END"==tmp) break;
		cout<<"Case "<<++casen<<": ";
		int n=tmp.size();
		s="";
		memset(rad,0,sizeof(rad));
		for(int i=0;i<n;i++){                                  
		    s+="#";s+=tmp[i];
		}s+='#';
		n=n*2+1;
		int i=0,j=1,k;                                        
		while(i<n){
			while(i-j>=0 && i+j<n && s[i-j]==s[i+j])
				j++;
			rad[i]=j-1;                                    
			k=1;
			while(k<=rad[i] && rad[i]-k!=rad[i-k]){
				rad[i+k]=min(rad[i-k],rad[i]-k);       
				k++;
			}
			i+=k;                                         
			j=max(j-k,0);                                      
		}                                                     
		for(i=0;i<n;i++)
			ans=max(ans,rad[i]);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}


