#include <iostream>
#include <string>
using namespace std;

const    int        maxn = 100;

int        n;
string    origin[maxn], replace1[maxn], sequence;

void init()
{
    int        i;

    for (i = 0; i < n; i++)
    {
        getline(cin, origin[i]);
        getline(cin, replace1[i]);
    }
    getline(cin, sequence);
}

void work()
{
    int        l, l2, i, pos;

    for (i = 0; i < n; i++)
    {
        pos = sequence.find(origin[i]);
        l = origin[i].length();
        while (pos != string::npos)
        {
            sequence.erase(pos, l);
            sequence.insert(pos, replace1[i]);
            pos = sequence.find(origin[i]);
        }
    }
    cout << sequence << endl;
}

int main()
{
    cin >> n;
    getchar();
    while (n != 0)
    {
        init();
        work();
        cin >> n;
        getchar();
    }
    return 0;
}


