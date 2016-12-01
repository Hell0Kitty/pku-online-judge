#include<stdio.h>

#define range 1010

int flag[2][2][2]={ {{-1,1},{1,1}},{{-1,-1},{1,-1}} };

int total;
int arr,col;
int x0,y0;  
int x,y;  
int UD,LR;
char direc[5];
int calcu[range][range][1];

inline bool square();
void direcMade();
inline bool vertax();
void derecChange();
inline bool side();
void initial();

int main()
{
    int N;  scanf("%d",&N);
    while(N--)
    {

        scanf("%d%d",&arr,&col);
        scanf("%d%d",&x0,&y0);
        getchar();
        gets(direc);

        total=0; 
        direcMade();  
        x=y0,y=arr-x0+1;  
        initial();
        while(1)
        {

            do{
                ++calcu[x][y][0];
                x += flag[UD][LR][0];  y += flag[UD][LR][1];
            }while( !side() );
            if( vertax() || calcu[x][y][0] != 0)  

            { 
                ++calcu[x][y][0];
                break;
            }
            derecChange();
        }

        for(int i=0; i!=range; ++i)
        {
            for(int j=0; j!=range; ++j)
            {
                if(calcu[i][j][0]!=0)
                  total += calcu[i][j][0]-1;
            }
        }
        printf("%d\n",total);
    }
    return 0;

}

inline bool square()  
{
     if(arr==col)
      return true;
     else return false;
}

void direcMade()  
{
     if(direc[0] == 'D')
     {
         if(direc[1] == 'R')
         { UD=1; LR=1; }
         else
         { UD=1; LR=0; }
     }
     else
     {
         if(direc[1] == 'R')
         { UD=0; LR=1; }
         else
         { UD=0; LR=0; }
     }
     return ;
}

inline bool vertax()
{
    if( (x==1 || x==col) && (y==1 || y==arr) )
      return true;
    return false;
}

void derecChange()  
{
     if( vertax() )  
       return ;
     if( x==1 || x==col ) 
       LR=(LR+1)%2;
     if( y==1 || y==arr ) 
       UD=(UD+1)%2;
     return ;

}

inline bool side()  
{
    if( x==1 || x==col || y==1 || y==arr)
      return true;
    return false;
}

void initial()
{
     for(int i=0; i!=range; ++i)
       for(int j=0; j!=range; ++j)
       calcu[i][j][0]=0;
}


