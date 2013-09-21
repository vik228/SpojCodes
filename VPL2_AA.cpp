#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	int cse = 0;
	while (t--)
	{
		cse++;
		float p0, p1, pf, t;
		scanf ("%f%f%f%f",&p0,&p1,&t,&pf);
		double ans = t * ((log (p1/pf))/(log (p0/p1)));
		ans += t;
		printf ("Scenario #%d: %0.2f\n",cse, ans);
	}
}
