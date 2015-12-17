#include <stdio.h>
#include <string.h>



#include <iostream>  
#include <algorithm>  
using namespace std;  
  
int sticks[64], n, len, num;  
bool used[64];  
  
bool compare(int a, int b)  
{  
    return a > b;      
}  
  
bool dfs(int cur, int left, int level)   
{   //cur: 当前已经计算的木棒编号，left:该段还剩的长度，level:已经成功的木棒数  
    if(left == 0) {//匹配一根木棒成功  
        if(level == num-2)  
            return true;  
        for(cur = 0; used[cur]; cur++)  
            ;  
        used[cur] = true;  
        if(dfs(cur+1, len-sticks[cur], level+1))  
            return true;  
        used[cur] = false;  
        return false;  
    } else {  
        if(cur >= n-1)  
            return false;  
        for(int i = cur; i < n; i++) {  
            if(used[i])  
                continue;  
            if((sticks[i] == sticks[i-1]) && !used[i-1])  
                continue;     
            if(sticks[i] > left)  
                continue;  
            used[i] = true;  
            if(dfs(i, left-sticks[i], level))  
                return true;  
            used[i] = false;  
        }     
        return false;  
    }  
}  
  
int main()  
{  
    while(cin>>n) {  
        if(n == 0)  
            break;  
        int sum = 0;  
        for(int i = 0; i < n; i++) {  
            scanf("%d", &sticks[i]);  
            sum += sticks[i];  
        }  
        sort(sticks, sticks+n, compare); //由大到小排序     
        bool end = false;  
        for(len = sticks[0]; len <= sum/2; len++) {  
            if(sum%len == 0) {  
                used[0] = true;  
                num = sum/len;  
                if(dfs(0, len-sticks[0], 0)) {  
                    end = true;  
                    printf("%d\n", len);  
                    break;    
                }     
                used[0] = false;  
            }     
        }  
        if(!end)  
            printf("%d\n", sum);  
        memset(used, 0, sizeof(used));  
    }  
    //system("pause");  
    return 0;  
}  
