#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 50
struct Box
{
	int h, w, d;
}b[MAX];
Box b_temp[3*MAX];
bool comp (Box i, Box j)
{
	return ((i.d*i.w) > (j.d*j.w));
}
int find_max_height (int n)
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		b_temp[idx] = b[i];
		idx++;
		b_temp[idx].h = b[i].w;
		b_temp[idx].d = min (b[i].h, b[i].d);
		b_temp[idx].w = max (b[i].h, b[i].d);
		idx++;
		b_temp[idx].h = b[i].d;
		b_temp[idx].d = min (b[i].h, b[i].w);
		b_temp[idx].w = max (b[i].h, b[i].w);
		idx++;
	}
	sort (b_temp, b_temp + 3*n, comp);
	/*
	for (int i = 0; i < 3*n; i++)
	{
		cout << b_temp[i].h << " " << b_temp[i].d << " " << b_temp[i].w << "\n";
	}
	*/
	int msh[3*n];
	for (int i = 0; i < 3*n; i++)
		msh[i] = b_temp[i].h;
	for (int i = 1; i < 3*n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((b_temp[i].d < b_temp[j].d and b_temp[i].w < b_temp[j].w) and (msh[i] < msh[j] + b_temp[i].h))
			{
				msh[i] = msh[j] + b_temp[i].h;
			}
		}
	}
	int val = -1;
	for (int i = 0; i < 3*n; i++)
	{
		val = max (val, msh[i]);
	}
	return val;
}
int main()
{
	int n;
	while (scanf ("%d",&n))
	{
		if (n == 0)
			break;
		int h, w, d;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d%d",&h, &w, &d);
			b[i].h = h;
			b[i].w = max (w, d);
			b[i].d = min (w, d);

		}
		cout << find_max_height (n) << "\n";
	}

}
