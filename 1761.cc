#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <stdio.h>
using namespace std;
struct data{
	int t;
	int n;
	bool ac;
};
class Qus{
public:
	map<string,data>acer;
	map<string,data>::iterator q;
	void push(int t,string name,bool ac){
		if(acer.find(name)==acer.end()){
			data da={t,1,ac};
			acer.insert(pair<string,data>(name,da));
			return ;
		}

			if(acer[name].ac==0){
				acer[name].t=t;
				acer[name].n++;	
				acer[name].ac=ac;
			}

	}
	void show(int id){
		float suma=0.0,sumb=0.0,sumc=0.0,d=0.0;
		for(q=acer.begin();q!=acer.end();q++){
			suma+=q->second.n;
			if(q->second.ac){
				d+=q->second.n;
				sumb+=q->second.t;
				sumc++;
			}
		}
		int out0=0;
		float out1,out2;
		if(sumc==0) out0=0,out1=0.0,out2=0.0;
		else
			out0=sumc,out1=d/sumc,out2=sumb/sumc;
		if(out0>0)printf("%c %d %.2lf %.2lf\n",char(id+'A'),out0,out1,out2);
		else printf("%c 0\n",char(id+'A'));
		acer.clear();
	}
};

int main(){
	int N,i,a,tt;
	char tqu,tac;
	string tn;
	Qus aq[9];
	bool first=1;
	while(cin>>N){
		if(!first)cout<<endl;
		for(i=0;i<N;i++){
			cin>>tt>>tn>>tqu>>tac;
			aq[tqu-'A'].push(tt,tn,tac=='A');
		}
		for(i=0;i<9;i++)
		aq[i].show(i);
		first=0;
	}	
	return 0;
}



