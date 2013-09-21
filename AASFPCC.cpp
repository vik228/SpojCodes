#include <iostream>
#include <cstdio>
#define MAX 50010
using namespace std;
struct range
{
	int t_start, t_end;
}r1[50010];
int my_binary_search (int n, int low, int high)
{
	//cout << "hii\n";
	while (low <= high)
	{
		int mid = low + (high - low)/2;
		//cout << mid << "\n";
		if (n > r1[mid].t_end)
		{
			low = mid + 1;
		}
		else if (n < r1[mid].t_start)
			high = mid - 1;
		else
			return mid + 1;
	}
}
int main()
{
	int N, Q;
	scanf ("%d%d",&N,&Q);
	int B_i;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&B_i);
		if (i == 0)
		{
			r1[i].t_start = 0;
			r1[i].t_end = B_i-1;
		}
		else
		{
			r1[i].t_start = r1[i-1].t_end + 1;
			r1[i].t_end = r1[i].t_start + B_i - 1;
		}
	}
	int q;
	while (Q--)
	{
		scanf ("%d",&q);
		printf ("%d\n",my_binary_search (q,0,N-1));
	}
	return 0;
}
