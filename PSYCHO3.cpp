#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100
int f[MAX];
vector <int> primes;
int phycoNumbers[1000];
bool isPhycoNum[1150];
bool isSubsetSum (int N, int sum)
{
	int possiblesum[sum+1];
	memset (possiblesum, 0, sizeof (possiblesum));
	possiblesum[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = sum; j >= phycoNumbers[i]; j--)
		{
			if (possiblesum[j-phycoNumbers[i]] == 1)
				possiblesum[j] = 1;
		}
	}
	return (possiblesum[sum] == 1);
}
void findPhycoNumbers ()
{
	int i = 0;
	int pychoNumbers[] = {4,9,16,25,36,49,64,81,100,121,144,169,180,196,225,252,256,289,300,324,361,396,400,441,450,468,484,529,576,588,612,625,676,684,700,720,729,784,828,841,882,900,961,980,1008,1024,1044,1089,1100,0};
	while (pychoNumbers[i] != 0)
	{
		isPhycoNum[pychoNumbers[i]] = true;
		i++;
	}

}
int main() 
{
	int T;
//	sieve();
	findPhycoNumbers ();
	scanf ("%d",&T);
	while (T--)
	{
		int N, K;
		scanf ("%d%d",&N,&K);
		int val;
		int sum = 0;
		int k = 0;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&val);
			if (isPhycoNum[val])
			{
				sum += val;
				phycoNumbers[k++] = val;
			}
		}
		//cout << sum << "\n";
		//cout << phycoNumbers.size() << "\n";
		if (K > sum)
			printf ("No\n");
		else if (isSubsetSum (k, K))
			printf ("Yes\n");
		else
			printf ("No\n");
	}
	return 0;
}
