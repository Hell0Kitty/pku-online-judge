#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char name[1000];
double A, R;
char unit[1000];
char temp[1000][1000];
int main()
{
    int k = 0;
    while (scanf("%lf", &A))
    {
        memset(name, 0, sizeof(name));
        memset(unit, 0, sizeof(unit));
        if (A < 0)
        {
            printf("Provides no significant amount of:\n");
            if (k > 0)      
            {
                for (int i = 0; i < k; i++)
                    printf("%s\n", temp[i]);
            }
            break;
        }
        scanf("%s%lf", unit, &R);
        getchar();
        fgets(name, 1000, stdin);     
        name[strlen(name) - 1] = '\0';
        double pec = A / R * 100;
        if (pec < 1)        
        {
            strcpy(temp[k++], name);
            continue;
        }
        else
            printf("%s %.1f %s %.0f%%\n", name, A, unit, pec);
    }
    return 0;
}


