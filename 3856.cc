#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
struct T
{
    int file;
    vector<int> v;
};
T mem[1200000];
map<string,int> mp;
int lm;
char str[12000],cmd[12000],dic[12000],ts[12000];
int cdn,lc;
const int root=0;
int dfs(int x)
{
    int cnt,i;
    cnt=0;
    if (mem[x].file != -1)
        return mem[x].file;
    for (i=0; i<mem[x].v.size(); i++)
    {
        cnt+=dfs(mem[x].v[i]);
    }
    return cnt;
}
int main()
{
    int i,j,tn,ls,lts;
    bool flag;
    while (true)
    {
        mp.clear();
        mem[root].v.clear();
        mem[root].file=-1;
        cmd[0]='\\';
        cmd[1]='\0';
        lc=1;
        cdn=0;
        lm=0;
        mp[cmd]=lm;
        lm++;
        flag=false;
        while (true)
        {
            if (flag == false)
            {
                gets(str);
            }

            flag=false;
            if (str[0] == '>' && str[1] == 'c' && str[2] == 'd')
            {
                sscanf(str,"%s%s",ts,dic);
                if (strcmp(dic,"..") == 0)
                {
                    lc=strlen(cmd);
                    while (cmd[lc-2] != '\\')
                        lc--;
                    lc--;
                    cmd[lc]='\0';
                    cdn=mp[cmd];
                }
                else
                {
                    if (dic[0] == '\\')
                    {
                        cmd[0]='\\';
                        cmd[1]='\0';
                        lc=1;
                        cdn=0;
                        strcpy(dic,dic+1);
                    }
                    if (dic[0] == '\0')
                        continue;
                    for (i=0,j=0; ; i++)
                    {
                        if (dic[i] == '\\' || dic[i] == '\0')
                        {
                            ts[j]='\\';
                            j++;
                            ts[j]='\0';
                            strcpy(ts,strcat(cmd,ts));
                            if (mp.find(ts) == mp.end())
                            {
                                mp[ts]=lm;
                                mem[lm].file=-1;
                                mem[lm].v.clear();
                                mem[cdn].v.push_back(lm);
                                strcpy(cmd,ts);
                                cdn=lm;
                                lm++;
                            }
                            else
                            {
                                strcpy(cmd,ts);
                                cdn=mp[cmd];
                            }
                            if (dic[i] == '\\')
                                j=0;
                            else
                                break;
                        }
                        else
                        {
                            ts[j]=dic[i];
                            j++;
                        }
                    }
                }
            }
            else if (str[0] == '>' && str[1] == 'd' && str[2] == 'i')
            {
                flag=true;
                while (true)
                {
                    gets(str);
                    ls=strlen(str);
                    if (str[0] == '>')
                        break;
                    for (i=0; str[i]; i++)
                    {
                        if (str[i] == ' ')
                            break;
                    }
                    if (str[i] == '\0')
                    {
                        str[ls]='\\';
                        ls++;
                        str[ls]='\0';
                        strcpy(dic,cmd);
                        strcat(dic,ts);
                        if (mp.find(dic) == mp.end())
                        {
                            mp[dic]=lm;
                            mem[lm].file=-1;
                            mem[lm].v.clear();
                            mem[cdn].v.push_back(lm);
                            lm++;
                        }
                    }
                    else
                    {
                        sscanf(str,"%s%d",ts,&tn);
                        lts=strlen(ts);
                        ts[lts]='\\';
                        lts++;
                        ts[lts]='\0';
                        strcpy(dic,cmd);
                        strcat(dic,ts);
                        if (mp.find(dic) == mp.end())
                        {
                            mp[dic]=lm;
                            mem[lm].file=tn;
                            mem[lm].v.clear();
                            mem[cdn].v.push_back(lm);
                            lm++;
                        }
                    }
                }
            }
            else if (str[0] == '>' && str[1] == 'd' && str[2] == 'e')
            {
                sscanf(str,"%s%s",ts,dic);
                if (dic[0] == '\\')
                {
                    strcpy(cmd,dic);
                    lc=strlen(cmd);
                    cmd[lc]='\\';
                    lc++;
                    cmd[lc]='\0';
                }
                else
                {
                    strcpy(cmd,strcat(cmd,dic));
                    lc=strlen(cmd);
                    cmd[lc]='\\';
                    lc++;
                    cmd[lc]='\0';
                }
                if (mp.find(cmd) == mp.end())
                    printf("0\n");
                else
                {
                    cdn=mp[cmd];
                    printf("%d\n",dfs(cdn));
                }
                break;
            }
            else if (str[0] == '>' && str[1] == 'e')
            {
                return 0;
            }
        }
    }
}



