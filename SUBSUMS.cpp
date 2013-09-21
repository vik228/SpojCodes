#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
long long input[34];
long long sum1[1<<17+1];
long long sum2[1<<17+1];
using namespace std;
long long find_no_of_subsets (long long input[],int N,long long A,long long B)
{
	int p = N/2;
	int k1 = (1<<p);
	int p1 = N-N/2;
	int k2 = (1<<p1);
	memset (sum1 , 0 , sizeof(sum1));
	memset (sum2 , 0 , sizeof(sum2));
	for ( int i = 0; i < k1; i++ )
	{
		for ( int j = 0; j < p; j++)
		{
			if ( i & (1<<j))
			{
				//cout << input[j] << " ";
				sum1[i]+= input[j];
			}
		}
		//cout << "\n";
	}
	for ( int i = 0; i < k2; i++ )
	{
		for ( int j = 0; j < p1; j++)
		{
			if ( i & (1<<j))
			{
				//cout << input[p + j] << " ";
				sum2[i]+= input[p + j];
			}
		}
	}
	//cout<< "\n";
	sort ( sum1,sum1 + k1 );
	sort ( sum2,sum2 + k2 );
	long long sub = 0;
	for ( int i = 0 ; i < k1; i++)
	{
		sub+= (upper_bound(sum2,sum2 + k2,B-sum1[i])-lower_bound(sum2,sum2 + k2,A-sum1[i]));
	}



	#ifdef DEBUG
	for (int i = 0; i < k1; i++)
		cout << sum1[i] << " ";
	cout << "\n";
	for (int j = 0; j < k2; j++)
		cout << sum2[j]<<" ";
	#endif

	return sub;
}
int main()
{
	int N;
	long long A,B;
	scanf ("%d",&N);

	scanf ("%lld%lld",&A,&B);

	for ( int i = 0; i < N; i++)
		scanf ("%lld",&input[i]);

	printf("%lld\n",find_no_of_subsets ( input , N , A , B));


	return 0;

}

