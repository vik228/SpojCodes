#include <iostream>
#include <cstdio>
using namespace std;
long long tree[1000010];
void update (int n, int idx, int val)
{
	while (idx <= n)
	{
		tree[idx]+= 1LL*val;
		idx+= (idx & -idx);
	}
}
long long query (int idx)
{
	long long ret_val = 0;
	while (idx > 0)
	{
		ret_val+= tree[idx];
		idx-= (idx & -idx);

	}
	return ret_val;
}
int readInt()
{
	int cc = getc(stdin);
	while (cc < '0' || cc > '9')
		cc = getc(stdin);
	int ret = 0;
	while (cc >= '0' && cc <= '9') {
		ret = ret * 10 + cc - '0';
		cc = getc(stdin);
	}
	return ret;
	
 
}
int main()
{
	int n,m,c;
	n = readInt();
	m = readInt();
	c = readInt();
	update (n,1,c);
	while (m--)
	{
		char q_type;
		scanf (" %c",&q_type);
		//cout << q_type << "\n";
		if (q_type == 'Q')
		{
			int val;
			val = readInt();
			printf ("%lld\n",query (val));
		}
		if (q_type == 'S')
		{
			int u,v,k;
			u = readInt();
			v = readInt();
			k = readInt();
			update (n,u,k);
			update (n,v+1,-k);
		}
			
	}
}
