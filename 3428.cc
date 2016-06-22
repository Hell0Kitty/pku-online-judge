#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char format[50050],  // format string
	 argument[1001][50050];

bool isDigit(char c)
{
	return '0'<=c && c<='9';
}

bool judgeInt( char args[])
{
	if(args[0]=='\0' || args[0]=='\n' ) 
		return false;
	for( int i=0;args[i] && args[i]!='\n' ;i++)
		if( isDigit(args[i])==false) return false;
	return true; 
}

int calPara( char format[] )
{
	int k = 0;
	for( int i=0; format[i] && format[i]!='\n' ;i++){
		if( format[i]=='%' ){
			i++;
			if( format[i]=='d' && judgeInt(argument[k]))  k++;
			else if( format[i]=='s' ) k++;
			else if( format[i]=='%' ) continue;
			else return -1;
		} 
	}
	return k; 
}

void printInt(char args[])
{
	int idx = 0;
	while( args[idx]=='0' )  idx++;
	if( args[idx]=='\n' || args[idx]=='\0' ){
		putchar('0');
		return ;
	}
	while( args[idx] &&  args[idx]!='\n' )    putchar(args[idx++]);
}

void printStr(char args[])
{
	for( int i=0;args[i] && args[i]!='\n' ;i++)
		putchar( args[i] );
}

void output(char format[],char args[][50050])
{
	int k = 0;
	for( int i=0; format[i] && format[i]!='\n' ;i++){
		if( format[i]=='%' ){
			i++;
			if( format[i]=='d' )    printInt(argument[k++]); 
			else if( format[i]=='s' ) printStr(argument[k++]);
			else if( format[i]=='%' ) putchar('%');
		} 
		else putchar( format[i] );
	}
}

int main(int argc, const char *argv[])
{
	gets(format);

	int nPara = 0;
	while(gets(argument[nPara]))  nPara++;

	if( calPara(format) != nPara )  printf("%s","ERROR");
	else    output(format,argument);	

	return 0;
}



