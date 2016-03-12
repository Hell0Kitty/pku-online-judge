/*=============================================================================
#     FileName: 2442.cpp
#         Desc: poj 2442
#       Author: zhuting
#        Email: cnjs.zhuting@gmail.com
#     HomePage: my.oschina.net/locusxt
#      Version: 0.0.1
#    CreatTime: 2013-12-22 17:51:34
#   LastChange: 2013-12-22 17:51:34
#      History:
=============================================================================*/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxm 2005
using namespace std;

/*
 * 维护一个最大值堆,其中始终有n个元素
 * 读入第一行只data数组中,排序
 * a.读入下一行至data2数组,排序
 * b.data2[0]与data中各项相加 ,加入最大值堆
 * c.data2[i]加上data中的第0项,所得值如果比堆头元素大,则continue;否则,堆pop后加入所得值,继续加data中的第1,2,3,4...项.(i >= 1)
 * d.将最大值堆导入到data数组
 * 重复abcd
 * 最后答案就在data中
 */

int main()
{
	int t = 0;
	int m = 0, n = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &m, &n);
		int data[maxm] = {0};
		int data2[maxm] = {0};

		for (int k = 0; k < n; ++k)
		{
			scanf("%d", &data[k]);
		}
		sort(data, data + n);

		for (int j = 1; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
				scanf("%d", &data2[k]);
			sort(data2, data2 + n);
			priority_queue <int, vector<int>, less<int> > pq;

			for (int k = 0; k < n; ++k)
			{
				pq.push(data2[0] + data[k]);
			}
			for (int k = 1; k < n; ++k)
			{
				for (int l = 0; l < n; ++l)
				{
					int tmp = data2[k] + data[l];
					if (tmp >= pq.top())
						break;
					pq.pop();
					pq.push(tmp);
				}
			}
			for (int k = n - 1; k >= 0; --k)
			{
				data[k] = pq.top();
				pq.pop();
			}
		}

		for (int j = 0; j < n; ++j)
			printf("%d ", data[j]);
		printf("\n");
	}
	return 0;
}
