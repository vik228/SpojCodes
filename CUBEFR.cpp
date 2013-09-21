#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define MAXN 1000000
int cube_numbers[1000001];
int cubes[831913];
using namespace std;
void fill_with_cube_numbers()
{
	memset(cube_numbers, 0, sizeof(cube_numbers));
	for ( int i = 2; i*i*i <= MAXN; i++)
	{
		int k = i*i*i;
		for ( int j = k; j <= MAXN; j+= k) cube_numbers[j] = 1;
	}
	int count = 0;
	for (int i = 0; i <= MAXN; i++)
	{
		if(cube_numbers[i] == 0)
			cubes[count++] = i;
	}
}

int main()
{
	fill_with_cube_numbers();
	/*
	for ( int i = 0; i < 831913; i++)
		cout << cubes[i] << "\n";
	exit(0);
	*/
	int T,N;
	scanf("%d",&T);
	int i = 1;
	while (T--)
	{
		scanf("%d",&N);
		//cout << cube_numbers[8] << "\n";
		if (cube_numbers[N] == 1)
		{
			printf("Case %d: Not Cube Free\n", i);
			i++;
		}
		else
		{
			int* ptr = lower_bound(cubes, cubes + 831913, N);
			int idx = ptr - cubes;
			printf ("Case %d: %d\n", i, idx);
			i++;
		}

	}
	return 0;

}
