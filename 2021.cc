#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
    int age;
    string name;
}Person;

//父亲和儿子名字键值对
multimap<string, string> father_son;
//儿子和儿子年龄键值对
map<string, int> son_age;
//儿子和儿子比父亲少多少岁键值对
map<string, int> person_toage;
//家族中每个成员
vector<Person> Family;

bool cmp(const Person &p1, const Person &p2)
{
    if (p1.age == p2.age)
    {
        return p1.name < p2.name;
    }
    else
    {
        return p1.age > p2.age;
    }
}

//用BFS遍历得出家族中每个人的年龄
void BFS()
{
    queue<pair<string, int> > Queue;
    Queue.push(make_pair("Ted", 100));
    while(!Queue.empty())
    {
        pair<string, int> p = Queue.front();
        Queue.pop();
        int nCount = father_son.count(p.first);
        if (nCount != 0)
        {
            //遍历父亲的所有儿子
            multimap<string, string>::iterator iter;
            for (iter = father_son.lower_bound(p.first); iter != father_son.upper_bound(p.first); iter++)
            {
                //儿子的年龄等于父亲的年龄减去父子年龄之差
                son_age[iter->second] = p.second - person_toage[iter->second];
                Person temp;
                temp.name = iter->second;
                temp.age = son_age[iter->second];
                Family.push_back(temp);
                //将当前儿子入队，作为后序的父亲
                Queue.push(make_pair(iter->second, son_age[iter->second]));
            }
        }
    }
}

int main()
{
    int nCase, n, age, nDataset = 0;
    string father, son;
    cin>>nCase;
    while(nCase--)
    {
        cin>>n;
        father_son.clear();
        son_age.clear();
        person_toage.clear();
        Family.clear();
        son_age.insert(make_pair("Ted", 100));
        ++nDataset;
        for (int i = 0; i < n; i++)
        {
            cin>>father>>son>>age;
            father_son.insert(make_pair(father, son));
            person_toage.insert(make_pair(son, age));
        }
        BFS();
        sort(Family.begin(), Family.end(), cmp);
        cout<<"DATASET "<<nDataset<<endl;
        for (vector<Person>::iterator iter = Family.begin(); iter != Family.end(); iter++)
        {
            cout<<iter->name<<" "<<iter->age<<endl;
        }
    }
    return 0;
}



