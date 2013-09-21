#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAX 10010
#define INF 100000010
#define MAXLEN 12
#define MAXSZ 2100000
struct G_Node
{
	int to, cost;
};
bool operator< (const G_Node& a, const G_Node& b)
{
	return b.cost < a.cost;
}
vector <G_Node> graph[MAX];
int d[MAX];
void dijkstra (int s, int n)
{
	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
	}
	priority_queue< G_Node, vector<G_Node>, less <G_Node> > pq;
	G_Node a1;
	a1.to = s;
	a1.cost = 0;
	d[s] = 0;
	pq.push(a1);
	while (!pq.empty())
	{
		G_Node top = pq.top();
		int u = top.to;
		int D = top.cost;
		pq.pop();
		//visited[u] = true;
		if (D <= d[u])
		{
			for (int j = 0; j < graph[u].size(); j++)
			{
				int v = graph[u][j].to;
				int c = graph[u][j].cost;
				if ((d[v] > d[u] + c))
				{
					d[v] = d[u] + c;
					G_Node b;
					b.to = v;
					b.cost = d[v];
					pq.push(b);
				}

			}
		}

	}

}
int getIdx (char str[][MAXLEN], char s1[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!strcmp (str[i], s1))
			return i;
	}
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
	//cout << "Entering main \n";
	int s;
	s = readInt();
	//cout << s << "\n";
	//idx = 0;
	//fillbuff();
	//sign = '+';
	while (s--)
	{
		char str[MAX][MAXLEN];
		int n;
		//rd.readInt(n);
		//scanf ("%d",&n);
		n = readInt();
		for (int i = 0; i <= n; i++)
		{
			graph[i].clear();
		}
		int k = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf ("%s",str[i-1]);
			int p;
			scanf ("%d",&p);
			while (p--)
			{
				int v, c;
				//rd.readInt (v);
				//rd.readInt (c);
				//scanf ("%d%d",&v,&c);
				v = readInt();
				c = readInt();
				G_Node g1;
				g1.to = v - 1;
				g1.cost = c;
				graph[i - 1].push_back (g1);

			}
		}
		int r;
		r = readInt();
		//rd.readInt (r);
		char s1[MAXLEN];
		char s2[MAXLEN];
		while (r--)
		{
			scanf ("%s %s",&s1, &s2);
			int idx1 = getIdx (str, s1, n);
			int idx2 = getIdx (str, s2, n);
			//cout << idx1 << " " << idx2 << "\n";
			dijkstra (idx1, n);
			printf ("%d\n",d[idx2]);
			//memset (visited, 0, sizeof (visited));
		}


	}
}




