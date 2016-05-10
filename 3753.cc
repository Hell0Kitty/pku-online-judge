#include <iostream>
#include <string>
using namespace std;
int SafeStrcpy2KeyWord(char* pDestBuffer, 
         char* pSourceString, 
         int nDestBufferSize, 
         char* szKeyWord); 
int main() {
 char s1[300],s2[300],s3[300];
 int len;
 while(scanf("%s",s1) !=EOF)
 {
  while(scanf("%s",s2) && strcmp(s2,"END") != 0)
  {
   len = SafeStrcpy2KeyWord(s3,s1,300,s2);
   if(len == 0)
    printf("0 NULL\n");
   else
    printf("%d %s\n",len,s3);
  }
 }
 return 0;
}

int SafeStrcpy2KeyWord(char* pDestBuffer, 
         char* pSourceString, 
         int nDestBufferSize, 
         char* szKeyWord) 

{
 if(nDestBufferSize == 0 || strcmp(szKeyWord,"NULL") == 0)
 {
  return 0;
 }
 char *k = strstr(pSourceString,szKeyWord);
 if(k == NULL)
 {
  strcpy(pDestBuffer,pSourceString);
  return strlen(pSourceString);
 }
 if(k-pSourceString==0|| k-pSourceString > nDestBufferSize)
 {
  return 0;
 }
 int i;
 for(i = 0;i < k-pSourceString; i++)
 {
  pDestBuffer[i] = pSourceString[i];
 }
 pDestBuffer[i] = 0;
 return i ;
}


