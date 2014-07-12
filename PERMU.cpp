#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		if (n%2 == 1)
			cout << -1 << "\n";
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (i%2 == 1)
					cout << i + 1 << " ";
				else
					cout << i - 1 << " ";
			}
			cout << "\n";
		}

	}
}
