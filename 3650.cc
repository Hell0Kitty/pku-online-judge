#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, ans;
    int i, len;
    while (getline(cin, input))
    {
          if (input == "#")  break;
          ans.clear();
          len = input.length();
          for (i = 0; i < len; i++)
          {
              if (input[i] == ' ')
                 ans += "%20";
              else if (input[i] == '!')
                 ans += "%21";
              else if (input[i] == '$')
                 ans += "%24";
              else if (input[i] == '%')
                 ans += "%25";
              else if (input[i] == '(')
                 ans += "%28";
              else if (input[i] == ')')
                 ans += "%29";
              else if (input[i] == '*')
                 ans += "%2a";
              else 
                 ans.push_back(input[i]);
          } 
          cout << ans << endl;
    }

}

