#include <iostream>
using namespace std;

int main()
{
    int n, k, s, t, r, i, j, ans, tmp, p;
    while (cin >> n >> k){
          for (i = 0; i < k; i++){
               cin >> s >> t >> r;
               tmp = 0; 
               p = 0;
               ans = 0; 
               while (1){
                      tmp++;
                      ans++; 
                      p += s;
                      if (p < n && tmp == t){
                          tmp = 0; 
                          ans += r; 
                      }
                      if (p >= n)  break; 
               } 
               cout << ans << endl; 
          } 
    } 

}



