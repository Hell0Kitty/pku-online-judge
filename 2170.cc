#include<iostream>
using namespace std;

int s[10][10][10]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,0,0,0,1,1,1,1,1,1,1,0,1,4,5,5,5,5,5,5,5,0,4,4,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,0,0,0,0,1,1,1,1,1,1,0,0,2,5,6,6,6,6,6,6,0,2,8,11,12,12,12,12,12,12,0,5,11,11,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,1,6,12,12,12,12,12,12,12,12,0,0,0,0,0,1,1,1,1,1,0,0,1,7,12,13,13,13,13,13,0,1,8,29,34,35,35,35,35,35,0,7,29,29,34,35,35,35,35,35,0,12,34,34,34,35,35,35,35,35,1,13,35,35,35,35,35,35,35,35,1,13,35,35,35,35,35,35,35,35,1,13,35,35,35,35,35,35,35,35,1,13,35,35,35,35,35,35,35,35,1,13,35,35,35,35,35,35,35,35,0,0,0,0,0,0,1,1,1,1,0,0,0,2,13,18,19,19,19,19,0,0,7,48,84,89,90,90,90,90,0,2,48,66,102,107,108,108,108,108,0,13,84,102,102,107,108,108,108,108,0,18,89,107,107,107,108,108,108,108,1,19,90,108,108,108,108,108,108,108,1,19,90,108,108,108,108,108,108,108,1,19,90,108,108,108,108,108,108,108,1,19,90,108,108,108,108,108,108,108,0,0,0,0,0,0,0,1,1,1,0,0,0,1,11,30,37,38,38,38,0,0,3,63,169,223,230,231,231,231,0,1,63,140,307,361,368,369,369,369,0,11,169,307,307,361,368,369,369,369,0,30,223,361,361,361,368,369,369,369,0,37,230,368,368,368,368,369,369,369,1,38,231,369,369,369,369,369,369,369,1,38,231,369,369,369,369,369,369,369,1,38,231,369,369,369,369,369,369,369,0,0,0,0,0,0,0,0,1,1,0,0,0,0,3,25,53,60,61,61,0,0,1,43,256,466,543,550,551,551,0,0,43,224,820,1127,1204,1211,1212,1212,0,3,256,820,893,1200,1277,1284,1285,1285,0,25,466,1127,1200,1200,1277,1284,1285,1285,0,53,543,1204,1277,1277,1277,1284,1285,1285,0,60,550,1211,1284,1284,1284,1284,1285,1285,1,61,551,1212,1285,1285,1285,1285,1285,1285,1,61,551,1212,1285,1285,1285,1285,1285,1285,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,16,68,108,117,118,0,0,0,21,277,842,1226,1329,1338,1339,0,0,21,287,1847,3234,3773,3876,3885,3886,0,1,277,1847,2376,4003,4542,4645,4654,4655,0,16,842,3234,4003,4003,4542,4645,4654,4655,0,68,1226,3773,4542,4542,4542,4645,4654,4655,0,108,1329,3876,4645,4645,4645,4645,4654,4655,0,117,1338,3885,4654,4654,4654,4654,4654,4655,1,118,1339,3886,4655,4655,4655,4655,4655,4655};

int n,w,h;

int main(){
	while(cin>>n>>w>>h) cout<<s[n-1][w-1][h-1]<<endl;
}


