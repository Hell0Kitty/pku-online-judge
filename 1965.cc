#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

const __int64 mod=10000000;
struct BigNum
{
	__int64 a[300];

	BigNum()
	{
		a[0]=1;
		a[1]=0;
	}

	BigNum(int x)
	{
		if(x>=mod) a[0]=2,a[1]=x/mod,a[2]=x%mod;
		else a[0]=1,a[1]=x;
	}

	BigNum(__int64 x)
	{
		stack<__int64> s;
		while(x)
		{
			s.push(x%mod);
			x/=mod;
		}
		a[0]=s.size();
		int k=0;
		while(!s.empty())
		{
			a[++k]=s.top();
			s.pop();
		}
	}

	BigNum(string str)
	{
		int i;
		for(i=0;i<str.length();i++) if(str[i]!='0') break;
		if(i==str.length()) 
		{
			a[0]=1;
			a[1]=0;
			return;
		}
		str=str.substr(i,str.length()-i);
		int p=str.length()%7,j;
		__int64 k;
		a[0]=0;
		if(p)
		{
			a[0]=1;
			k=0;
			for(i=0;i<p;i++) k=k*10+str[i]-'0';
			a[1]=k;
			str=str.substr(p,str.length()-p);
		}
		for(i=0;i<str.length();)
		{
			k=0;
			for(j=i;j<i+7;j++) k=k*10+str[j]-'0';
			a[++a[0]]=k;
			i=j;
		}
	}

	BigNum operator+(BigNum temp)
	{
		BigNum ans;
		__int64 i,j,k,p;
		if(a[0]>temp.a[0]) p=a[0];
		else p=temp.a[0];
		for(i=a[0],j=temp.a[0],k=p;j>=1&&i>=1;i--,j--,k--)
			ans.a[k]=a[i]+temp.a[j];
		if(j==0)
		{
			while(i>=1) ans.a[i]=a[i--];
		}
		else
		{
			while(j>=1) ans.a[j]=temp.a[j--];
		}
		ans.a[0]=0;
		for(i=p;i>=1;i--) 
		{
			ans.a[i-1]+=ans.a[i]/mod;
			ans.a[i]%=mod;
		}
		if(ans.a[0])
		{
			for(i=p+1;i>=1;i--) ans.a[i]=ans.a[i-1];
			ans.a[0]=p+1;
		}
		else ans.a[0]=p;
		return ans;
	}

	BigNum operator-(BigNum temp)
	{
		BigNum ans;
		int i,j;
		for(i=0;i<=a[0];i++) ans.a[i]=a[i];
		for(i=ans.a[0],j=temp.a[0];i>=1&&j>=1;i--,j--)
			ans.a[i]-=temp.a[j];
		for(i=ans.a[0];i>=1;i--) if(ans.a[i]<0)
		{
			ans.a[i]+=mod;
			ans.a[i-1]--;
		}
		for(i=1;i<=a[0];i++) if(ans.a[i]) break;
		if(i>a[0]) 
		{
			ans.a[0]=1;
			ans.a[1]=0;
			return ans;
		}
		for(j=i;j<=a[0];j++) ans.a[j+1-i]=ans.a[j];
		ans.a[0]=a[0]-i+1;
		return ans;
	}

	BigNum operator*(BigNum temp)
	{
		BigNum ans;
		int i,j,p=a[0]+temp.a[0]-1;
		memset(ans.a,0,sizeof(ans.a));
		for(i=a[0];i>=1;i--) for(j=temp.a[0];j>=1;j--)
			ans.a[i+j-1]+=a[i]*temp.a[j];
		ans.a[0]=0;
		for(i=p;i>=1;i--)
		{
			ans.a[i-1]+=ans.a[i]/mod;
			ans.a[i]%=mod;
		}
		if(ans.a[0])
		{
			for(i=p;i>=0;i--) ans.a[i+1]=ans.a[i];
			ans.a[0]=p+1;
		}
		else ans.a[0]=p;
		return ans;
	}

	BigNum operator/(int x)
	{
		BigNum ans;
		int i,j;
		__int64 p;
		for(i=1;i<=a[0];i++)
		{
			if(i==1)
			{
				ans.a[i]=a[i]/x;
				p=a[i]%x;
			}
			else
			{
				ans.a[i]=(p*mod+a[i])/x;
				p=(p*mod+a[i])%x;
			}
		}
		for(i=1;i<=a[0];i++) if(ans.a[i]) break;
		if(i>a[0]) 
		{
			ans.a[0]=1;
			ans.a[1]=0;
			return ans;
		}
		for(j=i;j<=a[0];j++) ans.a[j+1-i]=ans.a[j];
		ans.a[0]=a[0]-i+1;
		return ans;
	}

	int operator==(BigNum temp)
	{
		if(a[0]!=temp.a[0]) return 0;
		for(int i=1;i<=a[0];i++) if(a[i]!=temp.a[i]) return 0;
		return 1;
	}

	int operator>(BigNum temp)
	{
		if(a[0]>temp.a[0]) return 1;
		if(a[0]<temp.a[0]) return 0;
		for(int i=1;i<=a[0];i++) if(a[i]!=temp.a[i]) return a[i]>temp.a[i];
		return 0;
	}

	int operator<(BigNum temp)
	{
		if(a[0]<temp.a[0]) return 1;
		if(a[0]>temp.a[0]) return 0;
		for(int i=1;i<=a[0];i++) if(a[i]!=temp.a[i]) return a[i]<temp.a[i];
		return 0;
	}

	int operator<=(BigNum temp)
	{
		BigNum p;
		for(int i=0;i<=a[0];i++) p.a[i]=a[i];
		return !(p>temp);
	}

	int operator>=(BigNum temp)
	{
		BigNum p;
		for(int i=0;i<=a[0];i++) p.a[i]=a[i];
		return !(p<temp);
	}

	void print()
	{
		printf("%I64d",a[1]);
		for(int i=2;i<=a[0];i++) printf("%07d",(int)a[i]);
	}
};

BigNum low,high,mid,ans,p,temp,temp1;
string str;

void print(BigNum a)
{
	vector<int> V;
	int i,j;
	for(i=a.a[0];i>=1;i--) 
	{
		if(i>1)
		{
			for(j=1;j<=7;j++)
			{
				V.push_back((int)(a.a[i]%10));
				a.a[i]/=10;
			}
		}
		else
		{
			while(a.a[i]) 
			{
				V.push_back((int)(a.a[i]%10));
				a.a[i]/=10;
			}
		}
	}
	j=0;
	for(i=0;i<V.size();i++) j+=V[i];
	printf("%d ",j%10);
	for(i=V.size()-1;i>=10;i--) printf("%d",V[i]);putchar('.');
	for(i=9;i>=0;i--) printf("%d",V[i]);puts("");
}

int main()
{
	while(cin>>str)
	{
		p=BigNum(str);
		int i;
		for(i=1;i<=30;i++) p=p*BigNum(10);
		low=BigNum(1);
		high=p;
		while(low<=high)
		{
			mid=(low+high)/2;
			temp=mid*mid*mid;
			if(temp>=p) high=mid-BigNum(1);
			else low=mid+BigNum(1);
		}
		temp=low*low*low;
		temp1=high*high*high;
		if(temp==p) print(low);
		else if(temp1==p) print(high);
		else if(temp<p) print(low);
		else print(high);
	}
	return 0;
}



