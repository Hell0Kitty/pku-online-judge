#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
struct Tman
{
    string name;
    Tman *father;
    list<Tman *> sons;
};

map<string, Tman *> hash;
Tman *root;

void print(long dep, Tman *now)
{
    if(now == NULL) return;
    for(long i = 1; i <= dep; ++i)
        cout<<"+";
    cout<<now->name<<endl;;
    for(list<Tman *>::iterator j = now->sons.begin(); j != now->sons.end(); ++j)
        print(dep + 1, *j);
}

void hires(string n1, string n2) 
{
    Tman *boss = hash[n1];
    Tman *employee = new Tman();
    employee->name = n2;
    employee->father = boss;
    boss->sons.push_back(employee);
    hash[n2] = employee;
}

void fire(string n1)
{
    Tman *p = hash[n1];
    hash.erase(n1);
    while(p->sons.size() > 0)
    {
        p->name = p->sons.front()->name;
        hash[p->name] = p;
        p = p->sons.front();
    }    
    p->father->sons.remove(p);
    delete p;
}

void solve()
{
    string str1,str2;
    long i;
    cin>>str1;
    root = new Tman();
    hash[str1] = root;
    root->name = str1;
    while(cin>>str1)
    {
        if(str1 == "print")
        {
            print(0,root);
            cout<<"------------------------------------------------------------"<<endl;
        }
        else if(str1 == "fire")
        {
            cin>>str2;
            fire(str2);
        }
        else
        {
            cin>>str2;
            cin>>str2;
            hires(str1, str2);
        }
    }
}

int main()
{
    solve();
    return 0;
}



