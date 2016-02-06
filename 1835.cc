#include <cstdio>
#include <cstring>
using std::memset;

int direction[6][3] = {{1,0,0},
                       {0,1,0},
                       {0,0,1},
                       {-1,0,0},
                       {0,-1,0},
                       {0,0,-1}};

int head[3], face[3], position[3];

int dot(int x[3], int y[3])
{
    int ans = 0;
    for(int i = 0 ; i < 3; i++)
    ans += x[i]*y[i];
    return ans;
}

bool equal(int x[3],int y[3])
{
    for(int i = 0 ; i < 3; i++)
    if(x[i] != y[i])
    return false;
    return true;
}

void cross(int x[3],int y[3], int ans[3])
{
    ans[0] = x[1]*y[2] - x[2]*y[1];
    ans[1] = x[2]*y[0] - x[0]*y[2];
    ans[2] = x[0]*y[1] - x[1]*y[0];
    return;
}

void back()
{
    for(int i = 0 ; i < 3; i++)
    face[i] = -face[i];
}

void left()
{
    for(int i = 0 ; i < 6; i++)
    {
        if(dot(direction[i], head))
        continue;

        if(dot(direction[i], face))
        continue;

        int temp[3];
        cross(direction[i], face, temp);
        if(equal(head, temp) ==  false)
        continue;

        for(int j = 0 ; j < 3; j++)
        face[j] = direction[i][j];
        return;
    }
}

void right()
{
    for(int i = 0 ;i < 3; i++)
    left();
}

void up()
{
    int temp[3];
    for(int i = 0 ; i < 3; i++)
    temp[i] = face[i];
    for(int i = 0 ; i < 3; i++)
    face[i] = head[i];
    for(int i = 0 ; i < 3; i++)
    head[i] = -temp[i];
}

void down()
{
    for(int i = 0 ; i  < 3; i++)
    up();
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
        scanf("%d", &n);

        face[0] = 1; face[1] = 0; face[2] = 0;
        head[0] = 0; head[1] = 0; head[2] = 1;
        position[0] = 0; position[1] = 0; position[2] = 0;

        while(n--)
        {
            char op[10];
            int x;
            scanf("%s%d", op, &x);
            switch(op[0])
            {
                case 'l': left(); break;
                case 'r': right(); break;
                case 'f': break;
                case 'b': back(); break;
                case 'u': up(); break;
                case 'd': down(); break;
            }

            for(int i = 0 ; i < 3; i++)
            {
                position[i] += x * face[i];
            }
        }

        for(int i = 0 ; i < 3; i++)
        printf("%d ", position[i]);

        for(int i = 0 ; i < 6; i++)
        {
            if(equal(face, direction[i]))
            printf("%d\n", i);
        }
    }
}




