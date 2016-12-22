#include <iostream>
using namespace std;

int h[50050];

int main()
{
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> h[i];
    }
    if (h[1] >= h[2])//边界的处理 
       cout << 1 << endl;
    for (i = 2; i <= n; i++){
        if (i == n){
              if (h[i] >= h[i-1])
                   cout << i << endl;
        }
        else{ 
              if (h[i] >= h[i-1] && h[i] >= h[i+1])
                  cout << i << endl;
           }
    }
    return 0;
}



