#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
char ch[30010];
struct seg_tree
{
	int c_sum,m_sum;
}tree[90010];
void init(int n, int b, int e)
{
	if (b == e)
	{
		tree[n].c_sum = tree[n].m_sum = (ch[b] == '(' ? 1 : -1);
		return;

	}
	int mid = (b + e)/2;
	init (2*n, b, mid);
	init (2*n + 1, mid + 1, e);
	tree[n].c_sum = tree[2*n].c_sum + tree[2*n + 1].c_sum;
	tree[n].m_sum = min (tree[2*n].m_sum, tree[2*n].c_sum + tree[2*n + 1].m_sum);

}
void update (int n, int b, int e, int idx)
{
	if (b > e or b > idx or e < idx)
		return;
	if (b == e)
	{
		tree[n].c_sum = tree[n].m_sum = -tree[n].c_sum;
		return;
	}
	int mid = (b + e)/2;
	update (2*n,b,mid,idx);
	update (2*n + 1, mid+1, e, idx);
	tree[n].c_sum = tree[2*n].c_sum + tree[2*n + 1].c_sum;
	tree[n].m_sum = min (tree[2*n].m_sum,tree[2*n].c_sum + tree[2*n+1].m_sum);
}
int main()
{
	int n, cse = 1;
	int t = 10;
	while (scanf ("%d",&n) != EOF)
	{
		//cout << t << "\n";
		//continue;
		scanf ("%s",&ch);
		init (1,0,n-1);
		printf ("Test %d:\n", cse);
		cse++;
		int m;
		scanf ("%d",&m);
		while (m--)
		{
			int k;
			scanf ("%d",&k);
			if (k == 0)
			{
				if (!tree[1].c_sum and !tree[1].m_sum)
				{
					cout << tree[1].c_sum << " : " << tree[1].m_sum << "\n";
					printf ("YES\n");
				}
				else
				{
					cout << tree[1].c_sum << " : " << tree[1].m_sum << "\n";
					printf ("NO\n");
				}
			}
			else
			{
				update (1,0,n-1,k-1);

			}	
		}
	}
	return 0;
}
