#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node{
    double latitude, longitude, x, y, z;
}node[1111];

double Distance(const Node &a, const Node &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    while(cin >>n){
       for(int i=0; i<n; i++){
           scanf("%lf %lf", &node[i].latitude, &node[i].longitude);
           double lat = node[i].latitude/180;
           double lon = node[i].longitude/180;
           node[i].x = cos(lat)*cos(lon);
           node[i].y = cos(lat)*sin(lon);
           node[i].z = sin(lat);
       }

       int tag ;
       double Min = 1000000.0;
       for(int i=0; i<n; i++){
           double Max = 0.0;
           for(int j=0; j<n; j++){
              double tmp = Distance(node[i], node[j]);
              Max = max(tmp, Max);
           }
           if(Max < Min){         
              Min = Max;
              tag = i;
           }
       }

       printf("%.2lf %.2lf\n", node[tag].latitude, node[tag].longitude);
    }
    return 0;
}



