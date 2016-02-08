#include <deque>
#include <iostream>
using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
typedef struct tagRECT{
	int left;
	int top;
	int right;
	int bottom;
}RECT;
RECT CreateRect(int x, int y, int r)
{
	RECT tmp;
	tmp.left = x - r;
	tmp.top = y - r;
	tmp.bottom = y + r;
	tmp.right = x+ r;
	return tmp;
}
typedef deque<RECT>::iterator LPRECT;
// 如果矩形相交，lpRect2中存放相交结果
bool IntersectRect(LPRECT lpRect1, LPRECT lpRect2)
{
	if (((lpRect1->left < lpRect2->left) ? (lpRect1->right < lpRect2->left) : (lpRect2->right < lpRect1->left))
		|| ((lpRect1->top < lpRect2->top) ? (lpRect1->bottom < lpRect2->top) : (lpRect2->bottom < lpRect1->top)))
		return false;
	lpRect1->left = min(lpRect1->left, lpRect2->left);
	lpRect1->top = min(lpRect1->top, lpRect2->top);
	lpRect1->right = max(lpRect1->right, lpRect2->right);
	lpRect1->bottom = max(lpRect1->bottom, lpRect2->bottom);
	return true;
}
int CalcRectSize(LPRECT lpRect)
{
	return ((lpRect->right - lpRect->left)
			* (lpRect->bottom - lpRect->top));
}
int main(int argc, char* argv[])
{
	deque<RECT> dqSrcRect;			// 原始矩形集合
	deque<RECT> dqDstRect;			// 代表互不相交的矩形集合
	int nWidth = 0;
	int nHeight = 0;
	cin>> nWidth >> nHeight;

	int nCount = 0;
	cin>>nCount;
	while (nCount--)
	{
		int x, y, r;
		cin>>x>>y>>r;
		dqSrcRect.push_back(CreateRect(x, y, r));
	}
	while (!dqSrcRect.empty())
	{
		LPRECT pRect1 = dqSrcRect.begin();
		LPRECT pRect2 = dqDstRect.begin();
		bool bChanged = false;
		while (pRect2 != dqDstRect.end())
		{
			if (IntersectRect(pRect1, pRect2))
			{
				dqDstRect.erase(pRect2);	// 清除目的队列中能合并的矩形
				bChanged = true;
				break;
			}
			++pRect2;
		}

		if (!bChanged)		// 没有交集
		{
			dqDstRect.push_back(*pRect1);
			dqSrcRect.pop_front();
		}
	}
	int iRemainSize = nWidth * nHeight;
	for (LPRECT pRect = dqDstRect.begin();
				pRect != dqDstRect.end(); pRect++)
	{
		iRemainSize -= (pRect->right - pRect->left) * (pRect->bottom - pRect->top);
	}
	cout<<iRemainSize;
	return 0;
}



