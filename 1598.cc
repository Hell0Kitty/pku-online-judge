#include<iostream>
using namespace std;
int k,e,num[20],index,temp,m,times;
char keys[20][25],excuses[20][100],*str;
bool checkAlp(char x){
	if(x<'A'||x>'z'||(x>'Z'&&x<'a'))
		return false;
	return true;
}
int main(){
	times=1;
	while(!cin.eof()){
		cin>>k>>e;
		memset(keys,0,sizeof(keys));
		memset(excuses,0,sizeof(excuses));
		memset(num,0,sizeof(num));		
		for(int i=0;i<k;i++){
			cin>>keys[i];
		}
		cin.get();
		for(int i=0;i<e;i++){			

			cin.getline(excuses[i],100);
		}
		for(int i=0;i<e;i++){
			index=0;			
			str=excuses[i];
			while(str[index]!=0){
				while(str[index]!=0&&!checkAlp(str[index]))
					index++;
				if(str[index]==0)
					break;
				for(int j=0;j<k;j++){					
					m=0;
					temp=index;
					while(keys[j][m]!=0){						
						if((!checkAlp(str[temp]))||((keys[j][m]!=str[temp])&&((keys[j][m]-'a'+'A')!=str[temp])))
							break;
						m++;
						temp++;
					}
					if(keys[j][m]==0&&(!checkAlp(str[temp]))){
						num[i]++;						
						break;
					}
				}
				while(checkAlp(str[index]))
					index++;
			}
		}
		int max=0;
		for(int i=0;i<e;i++)
			if(num[i]>max)
				max=num[i];

		cout<<"Excuse Set #"<<times<<endl;
		for(int i=0;i<e;i++){
			if(num[i]==max)
				cout<<excuses[i]<<endl;
		}
		cout<<endl;
		times++;				
	}
	return 0;
}




