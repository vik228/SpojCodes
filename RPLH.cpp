#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int T,Ta,Sp;
	double ans;
	double pi = 2*acos(0.0);
	double ab = 180/pi;
	scanf ("%d",&T);
	int j = 1;
	while (T--)
	{
		scanf ("%d%d",&Ta,&Sp);
		double val = (Ta*9.806)/(Sp*Sp);
		if (val > 1 or val < -1)
		{
			printf ("Scenario #%d: -1\n",j);
			j++;
			continue;
		}
		ans = asin (val)/2;
		ans*= ab;
		if(ans > 45)
		{
			printf ("Scenario #%d: -1\n",j);
			j++;
		}
		else
		{
			printf ("Scenario #%d: %0.2lf\n",j,ans);
			j++;
		}

	}
	return 0;

}
