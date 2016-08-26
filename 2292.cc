#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 51234
#define lowbit(X) (X & (-X))
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

char str[123];
char p[123]="abcdefghijklmnopqrstuvwxyz+*/?";
int cnt[32];
void cal(char *str){
	int n=strlen(str);
	for(int i=0;i<n;++i){
		if(str[i]<='z' &&str[i]>='a')cnt[str[i]-'a']++;
		else if(str[i]=='+')cnt[26]++;
		else if(str[i]=='*')cnt[27]++;
		else if(str[i]=='/')cnt[28]++;
		else cnt[29]++;
	}
}
//浠ヤ綅缃甶缁撳熬鍒嗘垚j浠界殑鏈�皬鎸夐敭鏁�
int D[33][13];
int s[33][13];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		//init
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",str);
			cal(str);
		}

		memset(D,0x3f,sizeof(D));
		D[0][0]=0;
		for(int i=0;i<30;++i){
			for(int j=1;j<=12 && j<=i+1;++j){
				//琛ㄧず鏈�悗涓�鐨勯暱搴�
				for(int k=1;k<=19 && i+1-k>=0;++k){
					int tt=1,temp=0;
					for(int p=i+1-k;p<=i;++p){
						temp+=cnt[p]*tt;tt++;
					}
					if(D[i+1-k][j-1]+temp<=D[i+1][j]){
						D[i+1][j]=D[i+1-k][j-1]+temp;
						s[i+1][j]=i+1-k;
					}
				}
			}
		}
		stack<int >st;
		//int t=s[30][12];
		int t=30;
		for(int k=12;k>=2;--k){
			st.push(s[t][k]);
			t=s[t][k];
		}
		while(!st.empty()){
			cout<<p[st.top()];
			st.pop();
		}
		cout<<endl;

	}

	return 0;
}



