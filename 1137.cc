#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX_S 1024
#define MAX_H 10
using namespace std;

 struct statusN
 {
     int rNum, bit, step;
     statusN *next;
 }status[MAX_H + 2][MAX_S + 2];

 struct doorN
 {
     int f, t;
     int getOpp(int curS) //-1 not exist
     {
         if(curS == f) return t;
         else if(curS == t) return f;
         else return -1;
     }
 }door[MAX_H * MAX_H + 2];

 struct controlN
 {
     int hNum, lNum;
 }control[MAX_H * MAX_H + 2];

 int v[MAX_H + 2][MAX_S + 2];
 int exp[MAX_H + 2];
 int roomNum, doorNum, switNum;

 int getLight(int ex)
 {
     for(int i = 0; i < roomNum; i++)
         if(exp[i] == ex)
             return i;
     return -1;
 }

 void print(statusN *cur)
 {
     if(!cur->next)
         return;
     print(cur->next);

     int bitT = cur->bit, bitF = cur->next->bit, room2 = cur->rNum, room1 = cur->next->rNum;
     if(bitT == bitF)
         cout<<"- Move to room "<<room2+1<<"."<<endl;
     else
     {
         int ex = bitF ^ bitT;
         int which = getLight(ex);
         if(ex & bitT)
             cout<<"- Switch on light in room "<<getLight(ex) + 1<<"."<<endl;
         else
             cout<<"- Switch off light in room "<<getLight(ex) + 1<<"."<<endl;
     }
 }

 bool solve()
 {
     memset(v, 0, sizeof(v));
     statusN *final = &status[0][exp[0]];
     final->next = NULL;
     final->step = 0;    

     queue<statusN *> Q;
     v[0][exp[0]] = true;
     Q.push(final);
     bool finish = false;
     statusN *cur;

     int i;
     while(!Q.empty())
     {
         cur = Q.front();
         Q.pop();

         int bit = cur->bit, room = cur->rNum, step = cur->step;

         if(bit == exp[roomNum - 1] && room == roomNum - 1)
         {
             finish = true;
             break;
         }

         for(i = 0; i < doorNum; i++)
         {
             int opp;
             if((opp = door[i].getOpp(room)) != -1 && (bit & exp[opp]) > 0 && (!v[opp][bit]))
             {
                 v[opp][bit] = 1;
                 statusN *ns = &status[opp][bit];
                 ns->next = cur;
                 ns->step = step + 1;
                 Q.push(ns);
             }
         }
         for(i = 0; i < switNum; i++)
         {
             int ctrlNum = control[i].lNum;
             if(control[i].hNum == room)
             {
                 int newBit = bit ^ exp[ctrlNum];
                 if(v[room][newBit])
                     continue;
                 v[room][newBit] = 1;
                 statusN *ns = &status[room][newBit];
                 ns->next = cur;
                 ns->step = step + 1;
                 Q.push(ns);
             }
         }
     }
     if(!finish)
         return false;
     cout<<"The problem can be solved in "<<cur->step<<" steps:"<<endl;
     cur = &status[roomNum - 1][exp[roomNum - 1]];
     print(cur);
     return true;    
 }

 bool compare(controlN c1, controlN c2)
 {
     if(c1.hNum < c2.hNum)
         return true;
     else if(c1.hNum == c2.hNum)
     {
         if(c1.lNum <= c2.lNum)
             return true;
         return false;
     }
     return false;
 }

 int main()
 {
     int i, j, f, t;
     exp[0] = 1;
     for(i = 1; i <= MAX_H; i++)
         exp[i] = exp[i - 1]<<1;

     for(i = 0; i < MAX_H; i++)
     {
         for(j = 0; j < MAX_S; j++)
         {
             statusN cur = {i, j, 0, NULL};
             status[i][j] = cur;
         }
     }
     int caseN = 0;
     while(cin>>roomNum>>doorNum>>switNum && (roomNum + doorNum + switNum) != 0)
     {
         caseN++;
         for(i = 0; i < doorNum; i++)
         {
             cin>>f>>t;
             doorN cur = {f - 1, t - 1};
             door[i] = cur;
         }
         for(i = 0; i < switNum; i++)
         {
             cin>>f>>t;
             if(f == t) 
             {
                 switNum--;
                 i--;
                 continue;
             }
             controlN cur = {f - 1, t - 1};
             control[i] = cur;
         }
         cout<<"Villa #"<<caseN<<endl;
         sort(control, control + switNum, compare);
         if (!solve()) cout<<"The problem cannot be solved."<<endl;
         cout<<endl;
     }
     return 0;
 }


