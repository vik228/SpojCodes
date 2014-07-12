#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;
bool visited[20010];
struct val
{
	bitset<64> str;
	int rem, idx;
}ans;
void bfs (int n)
{
	queue<val> Q;
	val v1;
	v1.str.set (0, 1);
	v1.rem = v1.str[0]%n;
	v1.idx = 0;
	Q.push(v1);
	visited[v1.rem] = true;
	while (!Q.empty())
	{
		val v2 = Q.front();
		//cout << v2.str << "\n";
		Q.pop();
		if (v2.rem == 0)
		{
			ans = v2;
			return;
		}
		int rem = (v2.rem*10)%n;
		int rem1 = (v2.rem*10+1)%n;
		if (!visited[rem])
		{
			val v3;
			v3.rem = rem;
			v3.str = v2.str.set (v2.idx+1, 0);
			v3.idx = v2.idx+1;
			Q.push (v3);
			visited[rem] = true;

		}
		if (!visited[rem1])
		{
			val v3;
			v3.rem = rem1;
			v3.str = v2.str.set (v2.idx+1, 1);
			v3.idx = v2.idx+1;
			Q.push(v3);
			visited[rem1] = true;

		}
	}

}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		memset (visited, 0, sizeof (visited));
		ans.str.reset();
		int n;
		scanf ("%d",&n);
		bfs (n);
		//cout << ans.str << "\n";
		for (int i = 0; i <= ans.idx; i++)
		{
			cout << ans.str[i];
		}
		cout << "\n";
	}
	return 0;
}
