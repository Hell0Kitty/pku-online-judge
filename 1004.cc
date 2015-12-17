#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float sum = 0;
    float input;
    for (i = 0;i< 12;i++)
    {
        scanf("%f",&input);
        sum = input+sum;
    }
    printf("$%.2f\n",sum/12.0);
    return 0;
}
