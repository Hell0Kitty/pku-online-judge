#include <iostream>
using namespace std;

int main()
{
	int limitwidth;

	int x;
	int y;

	int totalwidth;//for all
	int totalheight;//for all

	cin>>limitwidth;

	while(limitwidth != 0)
	{
		totalwidth = 0;
		totalheight = 0;

		int sumwidthforeachline = 0;//for each line
		int maxheightforeachline = 0;//for each line

		cin>>x>>y;

		while(!((x == -1) && (y == -1)))
		{
			if(sumwidthforeachline + x <= limitwidth)//put it on the current line
			{
				sumwidthforeachline += x;

			}
			else//need to turn to next line
			{
				sumwidthforeachline = 0;

				totalheight += maxheightforeachline;

				maxheightforeachline = 0;

				sumwidthforeachline += x;

			}

			if(sumwidthforeachline > totalwidth)
					totalwidth = sumwidthforeachline;

			if(y > maxheightforeachline)
					maxheightforeachline = y;

			cin>>x>>y;
		}//end of while(!((x == -1) && (y == -1)))

		totalheight += maxheightforeachline;

		cout<<totalwidth<<" x "<<totalheight<<endl;

		cin>>limitwidth;
	}

	return 0;
}



