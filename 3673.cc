#include <iostream>  
#include <fstream>  
#include <cmath>  
#include <cstdio>  
#include <cstring>  
#include <limits>  
#include <string>  
#include <vector>  
#include <list>  
#include <set>  
#include <map>  
#include <queue>  
#include <stack>  
#include <algorithm>  
#include <cassert>  
  
using namespace std;  
  
int main()  
{  
    int A, B;     
    scanf("%d%d", &A, &B);  
    std::vector<int> digits;  
    while (A)  
    {  
        digits.push_back(A % 10);  
        A /= 10;  
    }  
  
    int sum = 0;  
    while (B)  
    {  
        int d = B % 10;  
        for (int i = 0; i < digits.size(); ++i)  
        {  
            sum += digits[i] * d;  
        }  
        B /= 10;  
    }  
  
    printf("%d\n", sum);  
    return 0;    
} 
