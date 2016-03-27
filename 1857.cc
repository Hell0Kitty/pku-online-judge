

#include<stdio.h>
int b,l,n;   
double r[1001];  
int w[1001];  
int s[1001]; 

void SolveDP()
{
    l *= 60;    
    r[0] = 0;

    int speed, weight;
    double time_best, time_now;

    for (int i = 1; i <= n; i++) {          
        scanf("%d%d", &(w[i]), &(s[i]));

        weight = w[i];
        speed = s[i];
        time_best = r[i - 1] + (double)l / (double)speed;

        for (int j = i - 1; j && (weight += w[j]) <= b; j-- ){
            if (s[j] < speed)
                speed = s[j];

            time_now = r[j - 1] + (double)l / (double)speed;
            if (time_now < time_best)
                time_best = time_now; 

        }
        r[i] = time_best;
    }
    printf("%.1f\n", r[n]);
}

int main(int argc, char *argv[])
{
    while (1) {

        scanf("%d%d%d",&b, &l, &n);

        if (b == 0 && l ==0 && n ==0)
            break;

        SolveDP();
    }
    return 0;
}



