#include <iostream>
#include <string>
using namespace std;

const    int        maxn = 105, maxl = 105, maxa = 105;

struct words
{
    string    sequence;
    string    word;
};

struct answers
{
    int        numbers[301];
};

int        n, len, total;
string    input;
answers    ans[maxa];
words    dictionary[maxn];

void makesequence(words &x)
{
    int        i, l = x.word.length(), temp;

    x.sequence = "";
    for (i = 0; i < l; i++)
    {
        temp = (x.word[i] - 'a') / 3 + 2;
        switch (x.word[i])
        {
            case    's'    :temp = 7; break;
            case    'v'    :temp = 8; break;
            case    'z'    :
            case    'y'    :temp = 9; break;
        }
        x.sequence += temp + '0';
    }
}

void init()
{
    int        i;

    total = 0;
    memset(ans, 0, sizeof(ans));
    getchar();
    for (i = 1; i <= n; i++)
    {
        getline(cin, dictionary[i].word);
        makesequence(dictionary[i]);
    }
    getline(cin, input);
    len = input.length();
}

void work(int start)
{
    int        i,l;

    if (start == len)
    {
        total++;
        for (i = 0; i <= ans[total - 1].numbers[0]; i++)
            ans[total].numbers[i] = ans[total - 1].numbers[i];
        return;
    }
    for (i = 1; i <= n; i++)
    {
        l = dictionary[i].word.length();
        if (l > len - start)
            continue;
        if (input.substr(start, l) == dictionary[i].sequence)
        {
            ans[total].numbers[0]++;
            ans[total].numbers[ans[total].numbers[0]] = i;
            work(start + l);
            ans[total].numbers[0]--;
        }
    }
}

bool bigger(answers a, answers b)
{
    int     l,i;

    l = a.numbers[0];
    if (l > b.numbers[0])
        l = b.numbers[0];
    for (i = 1; i <= l; i++)
    {
        if (dictionary[a.numbers[i]].word > dictionary[b.numbers[i]].word)
            return true;
        if (dictionary[a.numbers[i]].word < dictionary[b.numbers[i]].word)
            return false;
    }
    if (a.numbers[0] < b.numbers[0])
        return true;
    return false;
}

void sort()
{
    int        i,j;
    answers    t;

    for (i = 0; i < total - 1; i++)
        for (j = i + 1; j < total; j++)
            if (bigger(ans[i], ans[j]))
            {
                t = ans[i];
                ans[i] = ans[j];
                ans[j] = t;
            }
}

void print()
{
    int        i,j;

    for (i = 0; i < total; i++)
    {
        cout << dictionary[ans[i].numbers[1]].word;
        for (j = 2; j <= ans[i].numbers[0]; j++)
            cout << " " << dictionary[ans[i].numbers[j]].word;
        cout << ".\n";
    }
    cout << "--\n";
}

int main()
{
    cin >> n;
    while (n != 0)
    {
        init();
        work(0);
        sort();
        print();
        cin >> n;
    }
    return 0;
}


