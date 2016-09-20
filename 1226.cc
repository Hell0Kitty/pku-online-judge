#include<iostream>
#include<string.h>
using namespace std;

char x[101][101];

char c[101];

char str[101],str1[101];

int len=101,n;

void read(){
    int i,j,k,m,s,t;

    cin>>k;

    while(k--)

    {

        cin>>n;

        len=101;

        for(i=0;i<n;i++)

        {

            cin>>x[i];

            if(strlen(x[i])<len)

            {

                len=strlen(x[i]);

                strcpy(c,x[i]);

                m=i;

            }

        }

        for(i=len;i>=1;i--)

        {

            for(j=0;j<=len-i;j++)

            {

                for(s=0;s<i;s++)

                    str[s]=c[s+j];

                str[i]='\0';

                for(s=i-1;s>=0;s--)

                    str1[i-1-s]=str[s];

                str1[i]='\0';

                for(s=0;s<n;s++)

                    if(strstr(x[s],str)==NULL&&(strstr(x[s],str1)==NULL))

                        break;

                if(s>=n)

                {

                    cout<<i<<endl;

                    break;

                }

            }

            if(j<=len-i) break;

        }

        if(i==0) cout<<0<<endl;

    }

}

int main(){

    read();

    return 0;

}


