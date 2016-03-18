#include <iostream>
#define HASH_VAL 200000
using namespace std;
struct elem
{
    //x, y是当前地的坐标, pos是当前地在farms数组中对应的下标
    int x, y, pos;
    //指向下一个具有同样哈希值的elem，避免访问冲突
    elem *next;
    elem()
    {
        x = y = pos = 0;
        next = NULL;
    }
};
//哈希容器
struct hash
{
    //next指示第一个具有这个哈希值的farm
    elem *next;
}hashs[HASH_VAL + 2];
//存储每一块farm
struct farm
{
    int value;
    //标识是否被访问过
    bool v;
    elem *ptr;
}farms[HASH_VAL + 2];
int fNum, maxVal;
int getHashVal(int x, int y)
{
    __int64 temp = x * x + y * y;
    return temp % HASH_VAL;
}
int getPos(int x, int y, bool insertIfNotExist, int pos, int value)
{
    int hashVal = getHashVal(x, y);
    if(!hashs[hashVal].next)
    {
        if(!insertIfNotExist) return -1;
        else
        {
            elem *newPtr = new elem();
            newPtr->x = x; newPtr->y = y; newPtr->pos = pos;
            farms[pos].ptr = newPtr; farms[pos].v = false; farms[pos].value = value;
            hashs[hashVal].next = newPtr;
            return pos;
        }
    }
    if(hashs[hashVal].next->x == x && hashs[hashVal].next->y == y) return hashs[hashVal].next->pos;
    elem *curPtr = hashs[hashVal].next;
    while(curPtr->next)
    {
        if(curPtr->next->x == x && curPtr->next->y == y) return curPtr->next->pos;
        curPtr = curPtr->next;
    }
    if(!insertIfNotExist) return -1;
    else
    {
        elem *newPtr = new elem();
        newPtr->x = x; newPtr->y = y; newPtr->pos = pos;
        farms[pos].ptr = newPtr; farms[pos].v = false; farms[pos].value = value;
        curPtr->next = newPtr;
        return pos;
    }
}
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int dfs(int nodePos)
{
    farms[nodePos].v = true;
    int curVal = farms[nodePos].value;
    int curX = farms[nodePos].ptr->x, curY = farms[nodePos].ptr->y;
    int newX, newY;
    for(int p = 0; p < 4; p++)
    {
        newX = curX + dir[p][0];
        newY = curY + dir[p][1];
        int pos = getPos(newX, newY, false, 0, 0);
        if(pos == -1 || farms[pos].v) continue;
        curVal += dfs(pos);
    }
    return curVal;
}
int main()
{
    int i, x, y, value;
    while(scanf("%d", &fNum) && fNum != 0)
    {
        maxVal = INT_MIN;
        memset(hashs, 0, sizeof(hashs));
        for(i = 0; i < fNum; i++)
        {
            scanf("%d%d%d", &x, &y, &value);
            if(farms[i].ptr != NULL)
            {
                delete farms[i].ptr;
                farms[i].ptr = NULL;
            }
            getPos(x, y, true, i, value);
        }
        int curVal;
        for(i = 0; i < fNum; i++)
        {
            if(farms[i].v) continue;
            curVal = dfs(i);
            if(curVal > maxVal) maxVal = curVal;
        }
        printf("%d\n", maxVal);
    }
    return 0;
}



