#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 512
#define MAX2 100
unsigned A[MAX>>6];
int primes[MAX2];
#define chk(n) (A[(n)>>6]&(1<<(((n)>>1)&31)))
#define set(n) (A[(n)>>6]|=(1<<(((n)>>1)&31)))
using namespace std;
vector < vector <int> > v1(5001);
void sieve()
{
    for (unsigned i = 3; i*i < MAX; i+= 2)
    {
        int v = chk(i);
        if (v == 0)
        	for (unsigned j = i*i,k=i<<1; j < MAX; j+=k)
        	{
			set(j);
		}
    }
    int q = 1;
    primes[0] = 2;
    for (unsigned i = 3; i < MAX; i+=2)
    {
        int v = chk(i);
        if (v == 0)
	{
            primes[q++] = i;
	    //q++;
	}
    }
    //cout << q << "\n";
    //exit(0);
    
}
int div_count (int n)
{
	int ret_val = 1;
	for (int i = 0; (i < MAX2 and primes[i]*primes[i] <= n); i++)
	{
		//cout << primes[i] << "\n";
		int cnt = 0;
		if (n%(primes[i]) == 0)
		{
			while (n%(primes[i]) == 0)
			{
				cnt++;
				n/= (primes[i]);
			}
			if (cnt > 0)
			{
				cnt*= 2;
				ret_val*= cnt+1;
			}
		}
	}
	if (n != 1)
		ret_val*= 3;
	return ret_val;
}
int main ()
{
	sieve();
	for (int i = 2; i < 100000; i++)
	{
	    int k = div_count(i);
            int idx = (k+1)/2;
	    if (idx < 10000)
            	v1[idx].push_back(i);
	}
	int T;
	scanf ("%d",&T);
	vector < int >::iterator itlow, ithigh,it;
	int K;
	long long low, high;
	while (T--)
	{
		scanf ("%d",&K);
		scanf ("%lld%lld",&low,&high);
		int cnt;
		double idx1, idx2;
		idx1 = sqrt (low);
		idx2 = sqrt (high);
		int idx3 = (K+1)/2;
		//cout << idx1 << ": " << idx2 << "\n";
		int lo = (int)ceil (idx1);
		int hi = (int)floor (idx2);
		//cout << lo << ": " << hi << "\n"; 
		//cout << idx3 << "\n";
		/*
		for (it = v1[idx3].begin(); it != v1[idx3].end(); it++)
			cout << *it << "\t";
		cout << "\n";
		*/
		//cout << v1[idx3].size() << "\n";
		if (v1[idx3].size() > 0)
		{

			itlow = lower_bound (v1[idx3].begin(), v1[idx3].end(),lo);
			ithigh = upper_bound (v1[idx3].begin(), v1[idx3].end(), hi);
			cnt = ithigh - itlow;
			printf ("%d\n",cnt);
		}
		else
			printf ("0\n");
		
	}
	return 0;

}





