#include <iostream>
#include <vector>
using namespace std;

bool verify(vector<int> iv, int inx)
{
 int size = iv.size();
 int sum, sub;

 sum = inx + iv[inx];
 sub = inx - iv[inx];
 for(int i = 1; i < size; i++)
 {
  if(i + iv[i] == sum || i - iv[i] == sub)
   if(i != inx)
    return false;
 }
 return true;
}

int main()
{
 int n;

 cin>>n;
 vector<int> ivec(n+1);

 int  x, y;
 int counter = n;
 while(counter--)
 {
  cin>>x>>y;
  ivec[x] = y;
 }

 int temp;
 counter = 0;
 int  i, j, k;
 for(i = 1; i < n+1; i++)
  for(j = i+1; j < n+1; j++)
   for(k = j+1; k < n+1; k++)
   {
    temp = ivec[i];
    ivec[i] = ivec[j];
    ivec[j] = ivec[k];
    ivec[k] = temp;

    if(verify(ivec, i) && verify(ivec, j) && verify(ivec, k))
     counter++;

    temp = ivec[i];
    ivec[i] = ivec[j];
    ivec[j] = ivec[k];
    ivec[k] = temp;

    if(verify(ivec, i) && verify(ivec, j) && verify(ivec, k))
     counter++;

    temp = ivec[i];
    ivec[i] = ivec[j];
    ivec[j] = ivec[k];
    ivec[k] = temp;
   }

 cout<<counter<<endl;
}



