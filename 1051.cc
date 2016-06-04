#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map <char, string> morse;
map <string, char> remorse;
stack <int> num;
void init();

int main()
{
    int t, a, n;
    string s, s_morse, ans;
    init();
    cin>>t;
    for (int k = 1; k <= t; k++)
    {
        cin>>s;
        cout<<k<<": ";
        s_morse = "";
        num.empty();
        for (int i = 0; i < s.length(); i++)
        {
            s_morse = s_morse + morse[s[i]];
            num.push(morse[s[i]].length());
        }
        n = 0;
        while(!num.empty())
        {
            a = num.top();
            num.pop();
            ans = "";
            while(a--)
            {
                ans = ans + s_morse[n++];
            }
            cout<<remorse[ans];
        }
        cout<<endl;
    }
    return 0;
}

void init()
{
    morse['A'] = ".-";
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";
    morse['_'] = "..--";
    morse['.'] = "---.";
    morse[','] = ".-.-";
    morse['?'] = "----";

    remorse[".-"] = 'A';
    remorse["-..."] = 'B';
    remorse["-.-."] = 'C';
    remorse["-.."] = 'D';
    remorse["."] = 'E';
    remorse["..-."] = 'F';
    remorse["--."] = 'G';
    remorse["...."] = 'H';
    remorse[".."] = 'I';
    remorse[".---"] = 'J';
    remorse["-.-"] = 'K';
    remorse[".-.."] = 'L';
    remorse["--"] = 'M';
    remorse["-."] = 'N';
    remorse["---"] = 'O';
    remorse[".--."] = 'P';
    remorse["--.-"] = 'Q';
    remorse[".-."] = 'R';
    remorse["..."] = 'S';
    remorse["-"] = 'T';
    remorse["..-"] = 'U';
    remorse["...-"] = 'V';
    remorse[".--"] = 'W';
    remorse["-..-"] = 'X';
    remorse["-.--"] = 'Y';
    remorse["--.."] = 'Z';
    remorse["..--"] = '_';
    remorse["---."] = '.';
    remorse[".-.-"] = ',';
    remorse["----"] = '?';
}


