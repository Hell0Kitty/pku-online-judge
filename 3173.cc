#include <iostream>
using namespace std;
const int MAX = 25;
int triangle[MAX][MAX];

int main()
{
    int n, s, i, j, k;
    bool flag = false;
    cin >> n >> s;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= i; j++){
            triangle[j][i] = s;
            s++;
            if (s % 10 != 0){
                s %= 10;
            }
            else (++s) %= 10;
        }
    }

    for (i = 0; i < n; i++){
        flag = false;
        for (k = 0; k < i; k++){
             cout << " ";
        }
        for (j = 0; j < n; j++){
            if (triangle[i][j] != 0){
                if (flag)  cout << " ";
                cout << triangle[i][j];
                flag = true;
            }
            else{
                 cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}



