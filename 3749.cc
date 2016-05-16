#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

map<char, char> m;

int main()
{
    int i, len;
    string str, ans;
    ans.clear();
    m['A'] = 'V', m['B'] = 'W', m['C'] = 'X', m['D'] = 'Y', m['E'] = 'Z',
    m['F'] = 'A', m['G'] = 'B', m['H'] = 'C', m['I'] = 'D', m['J'] = 'E',
    m['K'] = 'F', m['L'] = 'G', m['M'] = 'H', m['N'] = 'I', m['O'] = 'J',
    m['P'] = 'K', m['Q'] = 'L', m['R'] = 'M', m['S'] = 'N', m['T'] = 'O',
    m['U'] = 'P', m['V'] = 'Q', m['W'] = 'R', m['X'] = 'S', m['Y'] = 'T', m['Z'] = 'U';
    while (getline(cin, str)){
          if (str == "ENDOFINPUT")  break;
          else if (str == "START")  continue;
          else if (str == "END"){
                cout << ans << endl;
                ans.clear();
          }
          else{
               len = str.length();
               for (i = 0; i < len; i++){
                   if (isalpha(str[i]))
                       ans.push_back(m[str[i]]);
                   else 
                       ans += str[i];
               }
          }
    }

}




