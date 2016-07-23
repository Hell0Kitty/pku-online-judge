#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N   15
#define INF     0x3f3f3f3f

int N;
int cost[MAX_N][MAX_N];                 // 串i连接串j的长度的增量
int D[1 << MAX_N][MAX_N];               // D[字串集合][串j] := 集合尾部为j时的累计长度的最小值（也就是花费）
bool reachable[1 << MAX_N][MAX_N];      // reachable[S][j] := 既定集合（已经拼成固定的序列了）能够拼上j
string piece[MAX_N];                    // 序列

/**
* 更新最小值
*/
template<typename numType>
inline bool update_min(numType &old, const numType &test)
{
    if (old > test)
    {
        old = test;
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> piece[i];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i != j && piece[j].find(piece[i]) != string::npos)
                {
                    piece[i] = piece[j];         // 序列j包含i，只保留母串
                }
            }
        }
        sort(piece, piece + N);
        N = unique(piece, piece + N) - piece;   // 排重

        int length[MAX_N];                      // 做个软cache
        for (int i = 0; i < N; ++i)
        {
            length[i] = piece[i].length();
        }

        // i右连接j
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int l = 0; l <= min(length[i], length[j]); ++l)
                {
                    if (piece[i].substr(length[i] - l) == piece[j].substr(0, l))
                    {
                        cost[i][j] = length[j] - l;
                    }
                }
            }
        }

        for (int bit = 0; bit < 1 << N; ++bit)
        {
            memset(D[bit], 0x3f, sizeof(D[bit]));
        }
        for (int i = 0; i < N; ++i)
        {
            D[1 << i][i] = length[i];
        }
        for (int bit = 0; bit < 1 << N; ++bit)
        {
            // 对每一种拼法，尝试拼接下一个串
            for (int i = 0; i < N; ++i)
            {
                if (D[bit][i] != INF)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        if (!((bit >> j) & 1))  // 如果没拼过j，尝试拼接j
                        {
                            update_min(D[bit | (1 << j)][j], D[bit][i] + cost[i][j]);
                        }
                    }
                }
            }
        }

        int bestLength = INF;
        for (int i = 0; i < N; ++i)
        {
            update_min(bestLength, D[(1 << N) - 1][i]);
        }

        memset(reachable, false, sizeof(reachable));
        for (int i = 0; i < N; ++i)
        {
            if (D[(1 << N) - 1][i] == bestLength)
            {
                reachable[(1 << N) - 1][i] = true;
            }
        }

        for (int bit = (1 << N) - 1; bit >= 0; --bit)
        {
            for (int i = 0; i < N; ++i)
            {
                if (reachable[bit][i])
                {
                    for (int j = 0; j < N; ++j)
                    {
                        if (i != j && ((bit >> j) & 1))
                        {
                            reachable[bit & ~(1 << i)][j] |= (D[bit & ~(1 << i)][j] + cost[j][i] == D[bit][i]);
                        }
                    }
                }
            }
        }

        string result = string(1, 'z' + 1);
        int appended = 0, last = -1;
        for (int i = 0; i < N; ++i)
        {
            if (reachable[1 << i][i] && update_min(result, piece[i]))
            {
                last = i;
            }
        }

        appended |= 1 << last;
        for (int _ = 0; _ < N - 1; ++_)
        {
            string tail = string(1, 'z' + 1);
            int key = -1;
            for (int i = 0; i < N; ++i)
            {
                if (!((appended >> i) & 1)) // 如果没有拼上过
                {
                    if (reachable[appended | (1 << i)][i]                                       // 倒着推，上一个状态可达
                            && D[appended][last] + cost[last][i] == D[appended | (1 << i)][i]   // 是最佳路径
                            && update_min(tail, piece[i].substr(length[i] - cost[last][i])))     // 字典序
                    {
                        key = i;
                    }
                }
            }
            last = key;
            appended |= 1 << key;
            result += tail;
        }
        printf("Scenario #%d:\n%s\n\n", t + 1, result.c_str());
    }
    return 0;
}



