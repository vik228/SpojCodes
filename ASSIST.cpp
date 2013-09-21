#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAX 34000
int flag[MAX];
int val[MAX];
int a[5000];
#define MAX2 3010
void pre_compute ()
{
	for (int i = 1, k = 2; i < MAX2; i++,k++)
	{
		while (flag[k] == 1)
		{
			k++;
			//continue;
		}
		a[i] = k;
		for (int j = k + 1,cnt = 0; j < MAX; j++)
		{
			if (flag[j])
				continue;
			cnt++;
			if (cnt == k)
			{
				flag[j] = 1;
				//cout << "cnt " << cnt << "j " << j << "\n";
				cnt = 0;
			}
		}
	}
}
int main()
{
	int n;
	pre_compute ();
	//exit(0);
	while (scanf ("%d",&n))
	{
		if (n == 0)
			break;
		printf ("%d\n",a[n]);

	}
}
