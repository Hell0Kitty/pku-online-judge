#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct shelf{
    int x, y, len, x1, x2;
}a[101];
int n, cx, cy, tx, ty;
int minpeg = 20000, mincost = 1000000;
bool cmp(const shelf &a, const shelf &b){
    return a.y < b.y;
}

void check(int k, int x, int &peg, int &cost){
    for (int i = k + 1; i < n; i++){
        if (a[i].y >= a[k].y + ty) break;
        if (a[i].x + a[i].len <= x || a[i].x >= x + tx) continue;
        if (a[i].x2 <= x){
            int rest;
            if (x - a[i].x1 <= a[i].x1) rest = 2 * (x - a[i].x1); else rest = x;
            if (rest < a[i].len) cost += a[i].len - rest;
        }
        else if (a[i].x1 >= x + tx){
            int rest;
            if (a[i].x2 - x - tx <= cx - a[i].x2) rest = 2 * (a[i].x2 - x - tx);
            else rest = cx - x - tx;
            if (rest < a[i].len) cost += a[i].len - rest;
        }
        else if (a[i].x1 <= x && a[i].x2 > x && a[i].x2 < x + tx){
            if (x == 0) peg += 2, cost += a[i].len;
            else{
                peg++;
                if (a[i].len > x) cost += a[i].len - x;
            }
        }
        else if(a[i].x1 > x && a[i].x1 < x + tx && a[i].x2 >= x + tx){
            if (x + tx == cx) peg += 2, cost += a[i].len;
            else{
                peg++;
                if (a[i].len > cx - x - tx) cost += a[i].len - cx + x + tx;
            }
        }
        else if (a[i].x1 <= x && a[i].x2 >= x + tx){
            if (x == 0 && tx == cx) peg += 2; else peg++;
            int rest = max(x, cx - x - tx);
            if (a[i].len > rest) cost += a[i].len - rest;
        }
        else if (a[i].x1 > x && a[i].x2 < x + tx){
            peg += 2;
            cost += a[i].len;
        }
    }
}

void work(int k){
    for (int i = 0; i + tx <= cx; i++){
        int peg = 0, cost = 0;
        if (i + a[k].len < a[k].x1) continue;
        if (a[k].x2 + a[k].len < i + tx) break;
        if (2 * (a[k].x1 - i) > a[k].len || 2 * (i + tx - a[k].x2) > a[k].len
          || a[k].x2 - i > a[k].len || i + tx - a[k].x1 > a[k].len) peg++;
        check(k, i, peg, cost);
        if (peg < minpeg || (peg == minpeg && cost < mincost)){
            minpeg = peg;  mincost = cost;
        }
    }
}

int main(){
    cin>>cx>>cy>>tx>>ty;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i].y>>a[i].x>>a[i].len>>a[i].x1>>a[i].x2;
        a[i].x1 += a[i].x;
        a[i].x2 += a[i].x;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++){
        if (a[i].y + ty > cy) break;
        if (a[i].len >= tx) work(i);
    }
    cout<<minpeg<<" "<<mincost;
    return 0;
}


