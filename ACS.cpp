#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int R[1235], C[5679];
int R1[1235], C1[5679];
void swap (int &A, int &B)
{
	A = A^B;
	B = A^B;
	A = A^B;
}
int getElement (int x, int y)
{
	return ((x-1)*5678 + y);
}
int main()
{
	char ch;
	int x, y;
	for (int i = 1; i <= 1234; i++)
	{
		R[i] = i;
		R1[i] = i;
	}
	for (int i = 1; i <= 5678; i++)
	{
		C[i] = i;
		C1[i] = i;
	}
	while (scanf ("%c",&ch) != EOF)
	{
		if (ch == 'R')
		{
			scanf ("%d%d",&x, &y);
			swap (R[x], R[y]);
			R1[R[x]] = x;
			R1[R[y]] = y;
			for (int i = 1; i <= 5; i++)
				cout << R1[i] << " ";
			cout << "\n";
			for (int i = 1; i <= 5; i++)
				cout << R[i] << " ";
			cout << "\n";
		}
		if (ch == 'C')
		{
			scanf ("%d%d",&x,&y);
			swap (C[x], C[y]);
			C1[C[x]] = x;
			C1[C[y]] = y;
		}
		if (ch == 'Q')
		{
			scanf ("%d%d",&x,&y);
			int idx1 = R[x];
			int idx2 = C[y];
			printf ("%d\n",getElement (idx1, idx2));
		}
		if (ch == 'W')
		{
			int z;
			scanf ("%d",&z);
			int idx1 = (z + 5677)/5678;
			int idx2 = (z - 1)%5678 + 1;
			int r_num = R1[idx1];
			int c_num = C1[idx2];
			printf ("%d %d\n", r_num, c_num);
		}
	}
	return 0;
}

