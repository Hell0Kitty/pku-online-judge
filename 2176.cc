#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Segment
{
    int l, r; //l是基本模式串的长度，r是重复次数
    char s[101]; //基本模式串
} dp[101][101];

int diglen(int num) 
{
    if(num < 10) return 1;
    else if(num < 100) return 2;
    else return 3;
}

Segment pack(const Segment &seg) //进行打包
{
    Segment ret;
    int digNum = diglen(seg.r); //求数字的字符个数
    if(seg.l * seg.r < seg.l + digNum + 2) //+2是因为括号有两个字符
    {
        ret.r = 1;
        ret.l = seg.l * seg.r;
        strcpy(ret.s, seg.s);
        for(int i = 1; i < seg.r; i++)
            strcat(ret.s, seg.s);
    }
    else
    {
        ret.r = 1;
        ret.l = seg.l + digNum + 2;
        sprintf(ret.s, "%d(%s)", seg.r, seg.s);
    }
    return ret;
}

int packlen(const Segment &seg) //返回打包后的最小长度
{
    return min(seg.l * seg.r, seg.l + 2 + diglen(seg.r));
}

int linklen(const Segment &seg1, const Segment &seg2, int &linkr) //返回将两个区间合并后的最小长度
{
    int len;
    if(seg1.l == seg2.l && 0 == strcmp(seg1.s, seg2.s)) //基本模式串一样则只需将重复次数相加
    {
        linkr = seg1.r + seg2.r;
        len = seg1.l;
    }
    else 
    {
        linkr = 1;
        len = packlen(seg1) + packlen(seg2);
    }
    return min(linkr * len, len + 2 + diglen(linkr));
}

Segment link(const Segment &seg1, const Segment &seg2) //将两个区间的串进行合并
{
    Segment ret;
    if(seg1.l == seg2.l && 0 == strcmp(seg1.s, seg2.s))
    {
        strcpy(ret.s, seg1.s);
        ret.l = seg1.l;
        ret.r = seg1.r + seg2.r;
    }
    else //基本模式串不同则需要先分别对两个区间进行打包，然后连接起来
    {
        Segment tmp1 = pack(seg1); 
        Segment tmp2 = pack(seg2);
        strcpy(ret.s, tmp1.s);
        strcat(ret.s, tmp2.s);
        ret.l = tmp1.l + tmp2.l;
        ret.r = 1;
    }
    return ret;
}

int main()
{
    char str[110];
    while(scanf("%s",str) != EOF)
    {
        int i, j, k;
        int len = strlen(str);
        for(i = 0; i < len; i++)
        {
            dp[i][i].l = dp[i][i].r = 1;
            dp[i][i].s[0] = str[i];
            dp[i][i].s[1] = '\0';
        }

        int tmpl, tmpr;
        int markl, markr, markj;
        for(k = 1; k < len; k++)
        {
            for(i = 0; i + k < len; i++)
            {
                markj = i;
                markl = linklen(dp[i][i], dp[i+1][i+k], markr);
                for(j = i + 1; j < i + k; j++)
                {
                    tmpl = linklen(dp[i][j], dp[j+1][i+k], tmpr);
                    if(tmpl < markl || (tmpl == markl && tmpr > markr))
                        markl = tmpl, markr = tmpr, markj = j;
                }
                dp[i][i+k] = link(dp[i][markj], dp[markj+1][i+k]);
            }
        }
        Segment tmp = pack(dp[0][len-1]);
        printf("%s\n",tmp.s);
    }
    return 0;
}



