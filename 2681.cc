<pre class="lang:c++ decode:true">
#include &lt;iostream&gt;
#include &lt;cstring&gt;
#include &lt;string&gt;
#include &lt;algorithm&gt;
#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;cstdlib&gt;
using namespace std;
int num[30];
char str1[200],str2[200];
int main()
{
	int n,i,j;
	scanf("%d",&amp;n);

	for(i=0;i&lt;n;i++)
	{
		memset(num,0,sizeof(num));
		if(i==0)
			getchar();
		gets(str1);
		for(j=0;str1[j];j++)
			num[str1[j]-'a']++;

		//getchar();
		gets(str2);
		for(j=0;str2[j];j++)
			num[str2[j]-'a']--;
		int sum=0;
		for(j=0;j&lt;26;j++)
		{
			if(num[j]&lt;0)
				num[j]=-num[j];
			sum+=num[j];
		}
		printf("Case #%d:  %d\n",i+1,sum);

	}
}



