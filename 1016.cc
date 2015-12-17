#include "stdio.h"
#include "string"
int main()
{
    int i=0, j=0, k=0;
    char strs[81]={0};
    while(scanf("%s", &strs) && strs[0]!='-')
    {
        char loop[16][10]={0}, tmp[31]={0}, tmpInt[3]={0};
        for(printf("%s ", strs), i=0; strs[i]!=0 && ++loop[0][strs[i]-48]; i++);
        for(i=0; i<10 && (loop[0][i]!=0 && (strcat(tmp, (sprintf(tmpInt, "%d", (int)loop[0][i]), tmpInt)), strcat(tmp, (sprintf(tmpInt, "%d", i), tmpInt))), true); i++);
        if(!strcmp(strs, tmp) && printf("is self-inventorying\n"))    continue;
        for(j=1; j<15; j++)
        {
            for(i=0; tmp[i]!=0 && ++loop[j][tmp[i]-48]; i++);
            for(i=0; i<j; i++)
            {
                for(k=0; k<10 && loop[i][k]==loop[j][k]; k++);
                if(k==10 && (j-i==1 ? printf("is self-inventorying after %d steps\n", j) : printf("enters an inventory loop of length %d\n", j-i)))
                    break;
            }
            if(i!=j)    break;
            for(i=0, tmp[0]=0; i<10 && (loop[j][i]!=0 && (strcat(tmp, (sprintf(tmpInt, "%d", (int)loop[j][i]), tmpInt)), strcat(tmp, (sprintf(tmpInt, "%d", i), tmpInt))), true); i++);
        }
        j==15 && printf("can not be classified after 15 iterations\n");
    }
    return 0;
}
