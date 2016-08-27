#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef int ElementType;
int ans;
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i , LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;
	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
		{
			ans += (LeftEnd - Lpos + 1); 
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}
	while(Lpos <= LeftEnd) 
	{
		TmpArray[TmpPos++] = A[Lpos++];
	}
	while(Rpos <= RightEnd)
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}
	for(i = 0; i < NumElements; ++i, --RightEnd)
		A[RightEnd] = TmpArray[RightEnd];
}
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center = 0;
	if(Left < Right)
	{
		Center = (Left + Right) >> 1;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}
void MergeSort(ElementType A[], int N)
{
	ElementType* TmpArray = NULL;
	TmpArray = (ElementType*) malloc(N * sizeof(ElementType));
	if(NULL != TmpArray)
	{
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
		printf("allocate temp memory fail\n");
}
int Arr[1001];
int mires[2][1001];
int main(int argc, char* argv[]){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; ++i)
			scanf("%d %d", &mires[0][i], &mires[1][i]);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(mires[0][i] == mires[1][j]) {
					Arr[i-1] = j;
					break;
				}
			}
		}
		ans = 0;
		MergeSort(Arr,n);
		printf("%d\n",ans);
	}
}



