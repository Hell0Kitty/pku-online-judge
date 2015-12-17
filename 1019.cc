#include <stdio.h>
#include <iostream>
using namespace std;
#define maxBound 100000000
int a[maxBound];

int digitsof(int i){

    int sum = 0;
    if(i == 0) return 1;
    while(i >0){
        i = i/10;
        sum ++;
    }
    return sum ;
}

void init(){
    int sumofdigit = 0;
    int i =1;
    a[1] = 1; 
    while( sumofdigit >=0 &&sumofdigit <= 2147483647){
        sumofdigit += a[i];
        a[i+1] = a[i] + digitsof(i+1);
        i++;
    }
//  puts("Finish initing...");
//  for (int x =1 ; x< 11; x++)
//  {
//      printf("a[%d] is %d\n", x, a[x]);
//  }

}
// char cal[]="11212312341234512345612345671234567812345678912345678910123456789101112345678910";
// void check(int x){
//  printf("The checked number is %c\n", cal[x-1]);
// 
// }

int main(){
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0;i< n;i++)
    {
        int question;
        scanf("%d",&question);
        int question_backup = question;
        int x = 1;
        while(question > a[x]){
            question -= a[x];
            x++;
        }
        
        int j;
        for (j= 1; j<= x;j++)
        {
            if (question > digitsof(j))
            {
                question -= digitsof(j);
            }else{
                break;
            }
        }
//      cout<< "The x is "<<x<<" The question is "<<question<<endl;
        int times = digitsof(j) -question;
        int final = j;
        
        for (int t = 1; t<= times;t++)
        {
            final = final /10;
        }
        printf("%d\n",final%10);
/*      check(question_backup);*/
    }


    return 0;
}
