#include<stdio.h>
#include<string.h>
#include<math.h>
#define bool int 

int option[5];
int order[5];
float number[5];
float curVal[4][5];

//输出时用到的临时变量
char outputStr[15];
char outputStr2[15];
char tempStr[15];
char tempStr2[15];

bool bfs(int k)
{
    int m;
    if(k==3)
    {
        if(fabs(24.0-curVal[3][0])==0)
            return 1;
        else
            return 0;
    }
    else
    {
        int i,j;
        for(i=0;i<3-k;i++)
        {
            for(j=0;j<4;j++)
            {
                switch(j)
                {
                case 0:
                    curVal[k+1][i]=curVal[k][i]+curVal[k][i+1];
                    break;
                case 1:
                    curVal[k+1][i]=curVal[k][i]-curVal[k][i+1];
                    break;
                case 2:
                    curVal[k+1][i]=curVal[k][i]*curVal[k][i+1];
                    break;
                case 3:
                    curVal[k+1][i]=curVal[k][i]/curVal[k][i+1];
                    break;
                }
                for(m=0;m<i;m++)
                    curVal[k+1][m]=curVal[k][m];
                for(m=i+1;m<3-k;m++)
                    curVal[k+1][m]=curVal[k][m+1];
                option[k]=j;
                order[k]=i;
                if(bfs(k+1))
                    return 1;
            }
        }
    }
    return 0;
}

void OutPut()
{
    if(order[1]>=order[0])
        order[1]++;
    order[2]=3-order[0]-order[1];

    char op[4]={'+','-','*','/'};
    sprintf(outputStr,"(%d%c%d)",(int)number[order[0]],op[ option[0] ],(int)number[order[0]+1]);
    strcpy(tempStr,outputStr);
    if(abs(order[0]-order[1])==2)
    {
        sprintf(outputStr2,"(%d%c%d)",(int)number[order[1]],op[ option[1] ],(int)number[order[1]+1]);
        strcpy(tempStr2,outputStr2);
        if(order[0]<order[1])
            sprintf(outputStr,"%.*s%c%.*s",sizeof(tempStr),tempStr,op[ option[2] ],sizeof(tempStr2),tempStr2);
        else
            sprintf(outputStr,"%.*s%c%.*s",sizeof(tempStr2),tempStr2,op[ option[2] ],sizeof(tempStr),tempStr);
    }
    else
    {
        if(order[0]<order[1])
            sprintf(outputStr,"(%.*s%c%d)",sizeof(tempStr),tempStr,op[ option[1] ],(int)number[order[1]+1]);
        else
            sprintf(outputStr,"(%d%c%.*s)",(int)number[order[1]],op[ option[1] ],sizeof(tempStr),tempStr);
        strcpy(tempStr,outputStr);
        if(order[2]==2)
            sprintf(outputStr,"%.*s%c%d",sizeof(tempStr),tempStr,op[ option[2] ],(int)number[order[2]+1]);
        else
            sprintf(outputStr,"%d%c%.*s",(int)number[order[2]],op[ option[2] ],sizeof(tempStr),tempStr);
    }
    printf("%s\n",outputStr);
}
int main()
{
    int i;
    for(i=0;i<4;i++)
    {
        scanf("%f",&number[i]);
        curVal[0][i]=number[i];
    }
    bfs(0);
    OutPut();
    return 0;
}


