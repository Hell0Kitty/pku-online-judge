#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef vector<int>::iterator VECINT_ITER;
int Josephus(int n, int k)
{  
	static vector<int> vecJosephus(1, 0);   
	if (n <= (int)vecJosephus.size())       
		return vecJosephus[n - 1];    
	int j = (Josephus(n - 1, k) + k) % n;   
	vecJosephus.push_back(j);   
	return j;

}
int main(void)
{ 
	for (int i = 0; i < 100000; Josephus(++i, 15));    
	for (int nSizeMin, nSizeMax; cin >> nSizeMin >> nSizeMax;) 
	{    
		if (nSizeMin > nSizeMax)        
			swap(nSizeMin, nSizeMax);       
		if (nSizeMin == 0 && nSizeMax == 0)          
			break;       
		vector<int> vecCover(nSizeMin / 2, 0);       
		for (int nSize = nSizeMin, nJump = 15; nSize <= nSizeMax; ++nSize) 
		{         
			int j = Josephus(nSize, nJump);            
			if (j > nSize / 2)                
				j = nSize - j;            
			if (j < vecCover.size())                
				vecCover[j] = 1;        
		}        
		VECINT_ITER ir = find(vecCover.begin() + 1, vecCover.end(), 0);     
		if (ir == vecCover.end())           
			cout << "Better estimate needed" << endl;       
		else            
			cout << ir - vecCover.begin() << endl;    
	}    
	return 0;
}


