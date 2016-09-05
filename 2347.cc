#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int t;
char str1[200], str2[200];
int a1, b1, c1;
int a2, b2, c2;
int a3, b3, c3;
int a4, b4, c4;
int len1, len2;

bool issign(char x){
	return (x=='+'||x=='-');
}

void solveEqua(char* str, int l, int r, int& a, int& b, int& c)
{
	a = b = c = 0;
	int op = 1;
	for(int i=l; i<r; i++)
	{
		if(str[i]==' ') continue;

		int sign=1, val=1;
		bool first=1;
		while(str[i]!=' ' && i<r)
		{
			if(issign(str[i]) && str[i+1]==' ') 
				op = str[i]=='+'? 1 : -1;

			if(isdigit(str[i]))//term
			{
				if(first){
					val = str[i]-'0';
					if(i>0 && issign(str[i-1]))
						sign = str[i]=='+'? 1 : -1;
					else sign = 1;
					first = 0;
				}
				else val+=str[i]-'0';

				if(i+1==r || !isdigit(str[i+1]))
					first = 1;
				else val*=10;

				if(i+1==r || str[i+1]==' ')
					c += val*sign*op;
			}

			if(issign(str[i]) && (str[i+1]=='x' || str[i+1]=='y'))
				sign = str[i]=='+'? 1 : -1;

			if(str[i]=='x')
				a += val*sign*op;
			else if(str[i]=='y')
				b += val*sign*op;
			i++;
		}
	}
}

int findPos(char* str){
	for(int i=0; i<strlen(str); i++){
		if(str[i] == '='){
			return i;
		}
	}
	return -1;
}

int gcd(int a, int b){
	if(b==0)	return a;
	return gcd(b, a%b);
}

int lcm(int a, int b){
	return a*b/gcd(a, b);
}

void solve(int a1, int b1, int c1, int a2, int b2, int c2, int& P, int& Q){

	if(a1==0 && b1==0 && c1!=0)	return ;
	if(a2==0 && b2==0 && c2!=0)	return ;

	if(!b1 && !b2) return;

	if((!a1 && !b1 && a2 && b2)
		||( a1 && b1 && !a2 && !b2))
		return;
	if(!a1 && !a2 && b1 && b2)
	{
		if(c1*b2 != c2*b1)	
			return;
		else{
			P=b1, Q=-c1;
			return;
		}
	}

	if(a1 && a2){
		int L = lcm(a1,a2);
		P = (b2*L/a2-b1*L/a1);
		Q = (c1*L/a1)-(c2*L/a2);
		return;
	}
	if(!a1 && b1){
		P = b1, Q = -c1; return;
	}
	if(!a2 && b2){
		P = b2, Q = -c2; return;
	}
}

void printAns(int P, int Q){
	if(P==0) puts("don't know");
	else{
		if(Q%P==0) printf("%d\n", Q/P);
		else{
			int g = gcd(P, Q);
			Q=Q/g; P=P/g;
			if(P<0)	Q=-Q, P=-P;
			printf("%d/%d\n", Q, P);
		}
	}
}

int main(){

	cin>>t;
	getchar();
	while(t--){
		gets(str1); len1 = strlen(str1);
		gets(str2); len2 = strlen(str2);

		int pos = findPos(str1);	
		solveEqua(str1, 0, pos, a1, b1, c1);
		solveEqua(str1, pos+1, len1, a2, b2, c2);

		pos = findPos(str2);
		solveEqua(str2, 0, pos, a3, b3, c3);
		solveEqua(str2, pos+1, len2, a4, b4, c4);
		int P=0, Q=0;
		solve(b1-b2, a2-a1, c2-c1, 
			b3-b4, a4-a3, c4-c3, P, Q);
		printAns(P, Q);

		P=Q=0;
		solve(a1-a2, b2-b1, c2-c1,
			a3-a4, b4-b3, c4-c3, P, Q);
		printAns(P, Q);
		if(t!=0) puts("");
		getchar();
	}
	return 0;
}



