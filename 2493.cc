#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
const int N = 10000+10;
char str[N];

int main(){
    //freopen("D:/a.txt", "r", stdin);
    int T, n, m, cas=1;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n); getchar();
        map<string, int> dict;
        for (int i=0; i<n; i++){
            gets(str);
            string word=str;
            if (word.size()>2) sort(word.begin()+1,word.end()-1);
            ++dict[word];
        }
        scanf("%d", &m);
        getchar();
        printf("Scenario #%d:\n", cas++);
        while (m--){
            gets(str);
            string line=str, word;
            int ans = 1;
            istringstream in(line);
            while (in >> word){
                if (word.size()>2)
                    sort(word.begin()+1, word.end()-1);
                ans *= dict[word];
            }
            printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}



