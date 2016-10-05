#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isSubStr(string str1, string str2) {
    char c;
    string::size_type pos = 0;
    string::size_type ix = 0;
    for(; ix != str2.size(); ++ix) {
        c = str2[ix];
        pos = str1.find(c, pos);  

        if(pos == string::npos) 
            break;
        else
            str1.erase(pos, 1); 
    }
    if(ix == str2.size())
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    string str1, str2;
    for(int i = 0; i < n; ++i) {
        cin >> str1 >> str2;
        string str2_backup = str2;
        reverse(str2.begin(), str2.end());
        if(isSubStr(str1, str2) || isSubStr(str1, str2_backup))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}


