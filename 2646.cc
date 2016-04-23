#include <iostream>
using namespace std;
double a[1000];
int main()
{
int n;
double avg, big, small;
while(cin >> n && n){
   big = small = avg = 0;
   for(int i=0; i<n; i++){
    cin >> a[i];
    avg += a[i];
   }
   avg /= (double)n;
   avg =(int)(avg*100+0.5)/100.0;
   for(int i=0; i<n; i++){
    if(a[i] <= avg)
     big += (avg - a[i]);
    else
     small -= (avg - a[i]);
   }
   cout.precision(2);
   cout << '$' << fixed << min(big, small) << endl;
  }
}



