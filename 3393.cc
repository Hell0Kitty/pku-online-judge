#include <stdio.h>
int month[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int lmonth[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
int leap(int year)
{
    if(year<1582)
    {
        if(year%4)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(year==1700)
        {
            return 1;
        }
        if((!(year%4)&&(year%100)) || !(year%400))
        {
            return 1;
        }
    }
    return 0;
}
int Sum_day(int y,int m)
{
    int i,j,day=1;
    for(i=1; i<y; i++)
    {
        if(leap(i))
        {
            day+=366;
        }
        else
        {
            day+=365;
        }
    }
    for(j=1; j<m; j++)
    {
        if(leap(i))
        {
            day+=lmonth[j];
        }
        else
        {
            day+=month[j];
        }
    }
    if(y>1752)
    {
        day-=11;
    }
    else if(y==1752 && m>9)
    {
        day-=11;
    }
    return day;
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        int ys,ms,ye,me,suml=0,sumg=0,day,i,j,flat;
        scanf("%d%d%d%d",&ys,&ms,&ye,&me);
        day=Sum_day(ys,ms);
       if(day%7>0&&day%7<4)
        {
            sumg++;
        }
        for(i=ys; i<ye; i++)
        {
            flat=0;
            if(leap(i))
            {
                flat=1;
            }
            if(i==ys)
            {
                j=ms;
            }
            else
            {
                j=1;
            }
            if(flat)
            {
                for(; j<=12; j++)
                {
                    day+=lmonth[j];
                    if(i==1752&&j==9)
                    {
                        day-=11;
                    }
                    if(day%7>0&&day%7<4)
                    {
                        suml++;
                        sumg++;
                    }
                }
            }
            else
            {
                for(; j<=12; j++)
                {
                    day+=month[j];
                    if(i==1752&&j==9)
                    {
                        day-=11;
                    }
                    if(day%7>0&&day%7<4)
                    {
                        suml++;
                        sumg++;
                    }
                }
            }
        }
        flat=0;
        if(leap(i))
        {
            flat=1;
        }
        if(i==ys)
        {
            j=ms;
        }
        else
        {
            j=1;
        }
        if(flat)
        {
            for(; j<=me; j++)
            {
                day+=lmonth[j];
                if(i==1752&&j==9)
                {
                    day-=11;
                }
                if(day%7>0&&day%7<4)
                {
                    suml++;
                    if(j!=me)
                    {
                        sumg++;
                    }
                }
            }
        }
        else
        {
            for(; j<=me; j++)
            {
                day+=month[j];
                if(i==1752&&j==9)
                {
                    day-=11;
                }
                if(day%7>0&&day%7<4)
                {
                    suml++;
                    if(j!=me)
                    {
                        sumg++;
                    }
                }
            }
        }
        printf("%d %d\n",suml,sumg);
    }
    return 0;
}


