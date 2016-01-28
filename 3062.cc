#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    char str[100];
     while(gets(str))
     {
         puts(str);
     }
    return 0;
}



